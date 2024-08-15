import RangeSelector from "devextreme-react/range-selector";
import { ClockData } from "@/types/genericTypes";
import { ValueChangedEvent } from "devextreme/viz/range_selector";

type DataRangeSelectorProps = {
  dataSource: ClockData[];
  filter: (range: ValueChangedEvent) => void;
};

export default function DateRangeSelector(props: DataRangeSelectorProps) {
  return <RangeSelector dataSource={props.dataSource} dataSourceField="date" onValueChanged={props.filter} />;
}
