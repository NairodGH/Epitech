import { TopCryptoDto } from "@/store/api/backendApi/endpoints/v1";

function getDefaultChartOptions(data: number[][], chartType: string) {
  const [minTime, maxTime, minValue, maxValue] = data.shift()!;
  return {
    tooltip: {
      trigger: "axis",
      axisPointer: {
        label: { precision: 0 },
      },
      valueFormatter: (value: number) => {
        if (typeof value === "number") return value.toFixed(2);
      },
    },
    legend: {
      data: ["Price (USD)"],
    },
    toolbox: {
      show: true,
      feature: {
        saveAsImage: {},
        dataZoom: {
          yAxisIndex: "none",
        },
        dataView: { readOnly: true },
        magicType: chartType == "line" && { type: ["line", "bar"] },
        restore: {},
      },
    },
    xAxis: {
      min: minTime,
      max: maxTime,
      type: "time",
    },
    yAxis: {
      min: minValue,
      max: maxValue,
      axisLabel: {
        formatter: function (value: number) {
          return Math.round(value);
        },
      },
      type: "value",
    },
    series: [
      {
        name: "Price (USD)",
        type: chartType,
        smooth: true,
        data: data.map(([index, ...values]) => [index, ...values]),
      },
    ],
  };
}

function getMainChartOptions(cryptos: TopCryptoDto[]) {
  const normalizedCryptos = cryptos.map((crypto) => {
    const minValue = Math.min(...crypto.price.map((price) => price.value));
    const maxValue = Math.max(...crypto.price.map((price) => price.value));
    return {
      ...crypto,
      price: crypto.price.map((price) => ({
        ...price,
        percent: ((price.value - minValue) / (maxValue - minValue)) * 100,
      })),
    };
  });
  return {
    legend: {
      data: normalizedCryptos.map((crypto) => crypto.name),
    },
    xAxis: {
      type: "time",
    },
    yAxis: {
      type: "value",
    },
    tooltip: {
      trigger: "axis",
      formatter: (params: any) => {
        const tooltipContent = params
          .map((item: any) => {
            return `${item.seriesName}: ${normalizedCryptos[
              item.seriesIndex
            ].price[item.dataIndex].value.toFixed(2)}`;
          })
          .join("<br/>");
        return `${params[0].axisValueLabel}<br/>${tooltipContent}`;
      },
    },
    series: normalizedCryptos.map((crypto) => ({
      name: crypto.name,
      type: "line",
      smooth: true,
      data: crypto.price.map((price) => [
        new Date(price.createdAt),
        price.percent,
      ]),
    })),
  };
}

export { getDefaultChartOptions, getMainChartOptions };
