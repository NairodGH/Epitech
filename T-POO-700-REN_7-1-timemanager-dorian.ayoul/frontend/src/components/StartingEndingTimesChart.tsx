import Chart, {
  ArgumentAxis,
  Series,
  Legend,
  Tooltip,
  CommonSeriesSettings,
  Label,
  Point,
  TickInterval,
  ValueAxis,
} from "devextreme-react/chart";
import { ClockData } from "@/types/genericTypes";

type StartingEndingTimesProps = {
  dataSource: ClockData[];
};

export default function StartingEndingTimesChart(props: StartingEndingTimesProps) {
  function customizeTooltip(pointInfo: any) {
    const elements: Record<string, any> = [];
    let count = 1;
    let startingAveragePushed = false;
    let endingAveragePushed = false;
    pointInfo.points.forEach((point: any) => {
      const filteredTime = point.valueText.match(/\d\d:\d\d/g);
      if (filteredTime.length == 2)
        elements.push(point.seriesName + " " + count++ + ": " + filteredTime[0] + "-" + filteredTime[1]);
      else if (point.seriesName == "Starting times average" && !startingAveragePushed) {
        startingAveragePushed = true;
        elements.push(point.seriesName + ": " + filteredTime[0]);
      } else if (point.seriesName == "Ending times average" && !endingAveragePushed) {
        endingAveragePushed = true;
        elements.push(point.seriesName + ": " + filteredTime[0]);
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
        <TickInterval hours={1} />
        <Label format={{ type: "hour" }} />
      </ValueAxis>
      <CommonSeriesSettings argumentField="date" />
      <Series name="Starting and ending times" rangeValue1Field="start" rangeValue2Field="end" type="rangebar" />
      <Series name="Starting times average" valueField="startAverage" type="line">
        <Point visible={false} hoverMode="none" selectionMode="none" />
      </Series>
      <Series name="Ending times average" valueField="endAverage" type="line">
        <Point visible={false} hoverMode="none" selectionMode="none" />
      </Series>
      <Tooltip enabled={true} shared={true} customizeTooltip={customizeTooltip} />
      <Legend horizontalAlignment="left" verticalAlignment="bottom" orientation="horizontal" />
    </Chart>
  );
}
