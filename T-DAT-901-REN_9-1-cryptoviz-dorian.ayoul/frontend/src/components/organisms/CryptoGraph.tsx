import { useEffect, useState } from "react";
import Container from "../templates/Container";
import {
  useCryptosControllerGetCryptoByIdQuery,
  useCryptosControllerGetCryptoHistoryQuery,
  CryptoCandlestickDto,
} from "@/store/api/backendApi/endpoints/v1";
import {
  List,
  ListItem,
  Radio,
  Spinner,
  Typography,
} from "@material-tailwind/react";
import dynamic from "next/dynamic";
import { getDefaultChartOptions } from "@/utils/chartOptions";
import Image from "next/image";
import useSocket from "@/socket/socket";

const ReactECharts = dynamic(() => import("echarts-for-react"), { ssr: false });

type CryptoGraphProps = {
  cmid: string;
};

type Period = "DAY" | "HOUR" | "MINUTE";
const periodArray: Period[] = ["DAY", "HOUR", "MINUTE"];
const intervalToValue = {
  DAY: 24 * 60 * 60 * 1000,
  HOUR: 60 * 60 * 1000,
  MINUTE: 60 * 1000,
};

export default function CryptoGraph(props: CryptoGraphProps) {
  const { cmid } = props;

  const [dateType, setDateType] = useState<Period>("MINUTE");
  const [data, setData] = useState<number[][]>([]);
  const { socket } = useSocket();

  const { data: crypto } = useCryptosControllerGetCryptoByIdQuery(
    { cmid },
    { skip: !cmid }
  );
  const { data: history } = useCryptosControllerGetCryptoHistoryQuery(
    { cmid, period: dateType },
    { refetchOnMountOrArgChange: true, skip: !cmid }
  );
  useEffect(() => {
    const maxTime = Date.now();
    if (history && dateType !== "DAY") {
      const minTime =
        maxTime - (history.priceHistory.length - 1) * intervalToValue[dateType];
      setData([
        [minTime, maxTime, history.lowestPriceBatch, history.highestPriceBatch],
        ...history.priceHistory.map((value, index) => [
          minTime + index * intervalToValue[dateType],
          value,
        ]),
      ]);
    }
    const getData = () => {
      socket.emit("candlestick", { cmid });
    };
    const onData = (candlestick: CryptoCandlestickDto) => {
      if (dateType === "DAY") {
        const { lowestLowPrice, highestHighPrice } =
          candlestick.candlestickValues.reduce(
            (acc, { lowPrice, highPrice }) => {
              return {
                lowestLowPrice: Math.min(acc.lowestLowPrice, lowPrice),
                highestHighPrice: Math.max(acc.highestHighPrice, highPrice),
              };
            },
            { lowestLowPrice: Infinity, highestHighPrice: -Infinity }
          );
        const minTime =
          maxTime -
          (candlestick.candlestickValues.length - 1) *
            intervalToValue[dateType];

        setData([
          [
            minTime - intervalToValue[dateType] / 2,
            maxTime,
            lowestLowPrice,
            highestHighPrice,
          ],
          ...candlestick.candlestickValues.map(
            ({ openingPrice, closingPrice, highPrice, lowPrice }, index) => [
              minTime + index * intervalToValue[dateType],
              openingPrice,
              closingPrice,
              highPrice,
              lowPrice,
            ]
          ),
        ]);
      }
    };
    getData();
    socket.on("candlestickJobDone", getData);
    socket.on("candlestick", onData);
    return () => {
      socket.off("candlestickJobDone", getData);
      socket.off("candlestick", onData);
    };
  }, [socket, cmid, dateType, history]);

  if (!crypto || data.length === 0) {
    return (
      <Container>
        <div className="flex flex-row justify-center p-10">
          <Spinner className="h-16 w-16" color="gray" />
        </div>
      </Container>
    );
  }

  return (
    <Container>
      <div className="flex flex-col gap-10">
        <div className="flex flex-row items-center gap-10">
          <Image
            src={crypto?.imageUrl ?? ""}
            alt="card-image"
            className="mb-4 h-12 w-12"
            width={100}
            height={100}
          />
          <h1 className="text-3xl">{crypto?.name}</h1>

          <List className="flex-row">
            {periodArray.map((period) => (
              <button key={period} onClick={() => setDateType(period)}>
                <label className="flex min-w-fit items-center">
                  <ListItem>
                    <Radio
                      id={`period-${cmid}-${period}`}
                      name={`period`}
                      className="hover:before:opacity-0"
                      ripple={false}
                      defaultChecked={dateType === period}
                    />
                    <Typography>{period}</Typography>
                  </ListItem>
                </label>
              </button>
            ))}
          </List>
        </div>

        <div>
          <ReactECharts
            option={getDefaultChartOptions(
              [...data],
              dateType === "DAY" ? "candlestick" : "line"
            )}
          />
        </div>
      </div>
    </Container>
  );
}
