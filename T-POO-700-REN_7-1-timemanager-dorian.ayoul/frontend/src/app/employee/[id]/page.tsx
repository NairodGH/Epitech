"use client";

import DateRangeSelector from "@/components/DateRangeSelector";
import StartingEndingTimesChart from "@/components/StartingEndingTimesChart";
import WorkedHoursChart from "@/components/WorkedHoursChart";
import Wrapper from "@/components/Wrapper";
import { useState } from "react";
import { ValueChangedEvent } from "devextreme/viz/range_selector";
import ProfileSummary from "@/components/ProfileSummary";
import { userClocks, userShow } from "@/api/endpoints/user";
import { useQuery } from "react-query";
import { useNotify } from "@/hooks/useNotify";
import { Clock } from "@/api/endpoints/clock";
import { ClockData } from "@/types/genericTypes";
import useTransformData from "@/hooks/useTransformData";

export default function Employee(props: { params: { id: string } }) {
  const notify = useNotify();
  const { formatData, getAverages } = useTransformData();

  const { data: employeeData } = useQuery({
    queryKey: "employee/info",
    queryFn: () => userShow({ id: props.params.id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!props.params.id,
  });

  const [formattedData, setFormattedData] = useState<ClockData[]>([]);

  const { isIdle: isClocksIdle, data: clocksData } = useQuery({
    queryKey: ["employee/userClocks", { userId: props.params.id! }],
    queryFn: () => userClocks({ userId: props.params.id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: (data) => {
      setFormattedData(formatData(data.data));
    },
    enabled: !!props.params.id,
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
        <ProfileSummary employee={employeeData?.data ?? {}} />
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
