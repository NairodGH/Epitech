import { TopCryptoDto } from "@/store/api/backendApi/endpoints/v1";
import dynamic from "next/dynamic";
import { getMainChartOptions } from "@/utils/chartOptions";

const ReactECharts = dynamic(() => import("echarts-for-react"), { ssr: false });

type MainGraphProps = {
  topCryptos: TopCryptoDto[];
};

export default function MainGraph(props: MainGraphProps) {
  const { topCryptos } = props;

  return <ReactECharts option={getMainChartOptions(topCryptos)} className="w-full h-full" />;
}
