"use client";

import Wrapper from "@/components/Wrapper";
import EmployeesTileView from "@/components/EmployeesTileView";
import { useQuery } from "react-query";
import { users } from "@/api/endpoints/user";
import { useNotify } from "@/hooks/useNotify";

export default function Employees() {
  const notify = useNotify();
  const { data: employeesData } = useQuery({
    queryKey: "employees",
    queryFn: users,
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
  });

  return (
    <Wrapper>
      <div className="flex flex-col gap-5 p-5">
        <div className="text-center text-3xl">Employees</div>
        <EmployeesTileView employees={employeesData?.data ?? []} />
      </div>
    </Wrapper>
  );
}
