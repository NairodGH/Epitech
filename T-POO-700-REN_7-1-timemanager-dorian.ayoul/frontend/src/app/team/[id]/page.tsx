"use client";

import Wrapper from "@/components/Wrapper";
import EmployeesTileView from "@/components/EmployeesTileView";
import { useQuery } from "react-query";
import { userShow } from "@/api/endpoints/user";
import { useNotify } from "@/hooks/useNotify";
import { teamClocks, teamShow, teamUsers } from "@/api/endpoints/team";
import DateRangeSelector from "@/components/DateRangeSelector";
import { useState } from "react";
import { ClockData } from "@/types/genericTypes";
import { ValueChangedEvent } from "devextreme/viz/range_selector_types";
import useTransformData from "@/hooks/useTransformData";

export default function Team({ params }: { params: { id: string } }) {
  const notify = useNotify();
  const { formatData, getAverages } = useTransformData();

  const { data: teamData } = useQuery({
    queryKey: "team/team",
    queryFn: () => teamShow({ id: params.id }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!params.id,
  });

  const { data: employeesData } = useQuery({
    queryKey: "team/teamEmployees",
    queryFn: () => teamUsers({ teamId: params.id }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!params.id,
  });

  const [formattedData, setFormattedData] = useState<ClockData[]>([]);

  const { data: dataManager } = useQuery({
    queryKey: "team/manager",
    queryFn: () => userShow({ id: teamData?.data.manager! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!teamData?.data.manager,
  });

  // Get the Clocks[] of all the team's members
  const { data: clocksData } = useQuery({
    queryKey: "team/clocks",
    queryFn: () => teamClocks({ id: params.id }),
    onError: (err) => {
      notify("error", (err as any).message ?? "An error occurred");
    },
    onSuccess: (data) => {
      setFormattedData(formatData(data.data));
    },
    enabled: !!params.id,
  });

  const [[startAverage, endAverage, differenceAverage], setAverages] = useState(getAverages(formattedData));

  function filter(range: ValueChangedEvent) {
    setAverages(
      getAverages(
        formattedData.filter((item) => {
          return range.value[0] <= item.date && item.date <= range.value[1];
        }),
      ),
    );
  }

  return (
    <Wrapper>
      <div className="flex flex-col gap-5 p-5">
        <div className="flex flex-col">
          <DateRangeSelector dataSource={formattedData} filter={filter} />
          <div className="flex flex-row justify-around">
            <div>
              Manager: {dataManager?.data.firstname} {dataManager?.data.lastname}
            </div>
            <div className="text-[#97C95C]">Starting hours average: {startAverage}</div>
            <div className="text-[#F5564A]">Ending hours average: {endAverage}</div>
            <div className="text-[#1DB2F5]">Worked hours average: {differenceAverage}</div>
          </div>
        </div>
        <EmployeesTileView employees={employeesData?.data ?? []} id={params.id} />
      </div>
    </Wrapper>
  );
}
