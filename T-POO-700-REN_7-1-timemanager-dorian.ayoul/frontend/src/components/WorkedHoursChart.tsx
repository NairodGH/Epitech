import { ClockData } from "@/types/genericTypes";
import Chart, {
  ArgumentAxis,
  Series,
  Legend,
  Tooltip,
  CommonSeriesSettings,
  Label,
  Point,
  ValueAxis,
} from "devextreme-react/chart";

type WorkedHoursChartProps = {
  dataSource: ClockData[];
};

export default function WorkedHoursChart(props: WorkedHoursChartProps) {
  function customizeTooltip(pointInfo: any) {
    const elements: Record<string, any> = [];
    let count = 1;
    let averagePushed = false;
    pointInfo.points.forEach((point: any) => {
      if (point.seriesName == "Worked hours")
        elements.push(point.seriesName + " " + count++ + ": " + point.valueText.match(/\d\d:\d\d/)[0]);
      else if (!averagePushed) {
        averagePushed = true;
        elements.push(point.seriesName + ": " + point.valueText.match(/\d\d:\d\d/)[0]);
      }
    });
    return { text: elements.join("\n") };
  }

  return (
    <Chart dataSource={props.dataSource}>
      <ArgumentAxis>
        <Label rotationAngle={-60} displayMode="rotate" />
      </ArgumentAxis>
      <ValueAxis valueType="datetime" minValueMargin={0.1} maxValueMargin={0.1}>
        <Label format={{ type: "hour" }} />
      </ValueAxis>
      <CommonSeriesSettings argumentField="date" />
      <Series name="Worked hours" valueField="difference" type="bar" />
      <Series name="Average" valueField="differenceAverage" type="line">
        <Point visible={false} hoverMode="none" selectionMode="none" />
      </Series>
      <Tooltip enabled={true} shared={true} customizeTooltip={customizeTooltip} />
      <Legend horizontalAlignment="left" verticalAlignment="bottom" orientation="horizontal" />
    </Chart>
  );
}
