export type Period = "DAY" | "HOUR" | "MINUTE";

const symbolSize = 5;

function getOptions(
  minValue: number,
  maxValue: number,
  data: number[][],
  period: Period
) {
  return {
    tooltip: {
      trigger: "axis",
    },
    legend: {
      data: ["Price (USD)"],
    },
    toolbox: {
      show: true,
      feature: {
        saveAsImage: { show: true },
      },
    },
    xAxis: {
      min: 0,
      max: data.length - 1,
      type: "value",
      axisLine: { onZero: false },
    },
    yAxis: {
      min: minValue,
      max: maxValue,
      type: "value",
      axisLine: { onZero: false },
    },
    series: [
      {
        name: "Price (USD)",
        type: "line",
        smooth: true,
        symbolSize: symbolSize,
        data: data,
      },
    ],
  };
}

export { getOptions };
