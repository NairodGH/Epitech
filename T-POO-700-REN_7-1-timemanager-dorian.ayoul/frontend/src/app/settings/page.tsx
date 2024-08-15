"use client";

import Wrapper from "@/components/Wrapper";
import SettingsForm from "@/components/SettingsForm";
import { UserAction, userShow } from "@/api/endpoints/user";
import { useQuery } from "react-query";
import { useJWT } from "@/hooks/useJWT";
import { useNotify } from "@/hooks/useNotify";

export default function Settings() {
  const { id } = useJWT();
  const notify = useNotify();

  const { isIdle: isUserInfoIdle, data: userData } = useQuery({
    queryKey: ["dashboard/userInfo", { userId: id! }],
    queryFn: () => userShow({ id: id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!id,
  });

  return (
    <Wrapper>
      <div className="flex items-center justify-center w-min-full h-min-full">
        <SettingsForm employee={userData?.data as UserAction} />
      </div>
    </Wrapper>
  );
}
