"use client";

import Wrapper from "@/components/Wrapper";
import DateRangeSelector from "@/components/DateRangeSelector";
import WorkedHoursChart from "@/components/WorkedHoursChart";
import StartingEndingTimesChart from "@/components/StartingEndingTimesChart";
import { useState } from "react";
import { ValueChangedEvent } from "devextreme/viz/range_selector";
import ClockInOutButton from "@/components/ClockInOutButton";
import { useQuery } from "react-query";
import { UserAction, userClocks, userShow } from "@/api/endpoints/user";
import { useJWT } from "@/hooks/useJWT";
import { useNotify } from "@/hooks/useNotify";
import { ClockData } from "@/types/genericTypes";
import useTransformData from "@/hooks/useTransformData";

export default function Dashboard() {
  const { id } = useJWT();
  const notify = useNotify();
  const { formatData, getAverages } = useTransformData();

  const { isIdle: isUserInfoIdle, data: userData } = useQuery({
    queryKey: ["dashboard/userInfo", { userId: id! }],
    queryFn: () => userShow({ id: id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!id,
  });

  const [formattedData, setFormattedData] = useState<ClockData[]>([]);

  const { isIdle: isClocksIdle, data: clocksData } = useQuery({
    queryKey: ["dashboard/userClocks", { userId: id! }],
    queryFn: () => userClocks({ userId: id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: (data) => {
      setFormattedData(formatData(data.data));
    },
    enabled: !!id,
  });

  const [filteredData, setFilteredData] = useState(formattedData);

  function filter(range: ValueChangedEvent) {
    const result = structuredClone(formattedData).filter((item) => {
      return range.value[0] <= item.date && item.date <= range.value[1];
    });
    const [startAverage, endAverage, differenceAverage] = getAverages(result);
    result.forEach((item) => {
      item.start = "2023T" + item.start;
      item.end = "2023T" + item.end;
      item.difference = "2023T" + item.difference;
      item.startAverage = "2023T" + startAverage;
      item.endAverage = "2023T" + endAverage;
      item.differenceAverage = "2023T" + differenceAverage;
    });
    setFilteredData(result);
  }

  return (
    <Wrapper>
      <div className="grid grid-flow-row md:grid-flow-col md:grid-rows-2 grid-cols-1 md:grid-cols-3 gap-4 p-4">
        <ClockInOutButton employee={userData?.data as UserAction} />
        <div>
          <DateRangeSelector dataSource={formattedData} filter={filter} />
        </div>
        <div className="md:col-span-2">
          <WorkedHoursChart dataSource={filteredData} />
        </div>
        <div className="md:col-span-2">
          <StartingEndingTimesChart dataSource={filteredData} />
        </div>
      </div>
    </Wrapper>
  );
}
