import { CardBody, List, ListItem, Radio, Typography } from "@material-tailwind/react";
import Container from "../templates/Container";
import MainGraph from "./MainGraph";
import { TopCryptoDto, useFeedsControllerGetDashboardFeedsQuery } from "@/store/api/backendApi/endpoints/v1";
import ArticlePreview from "../molecules/ArticlePreview";
import { useEffect, useState } from "react";
import useSocket from "@/socket/socket";

type Period = "YEAR" | "MONTH" | "DAY";
const periodArray: Period[] = ["YEAR", "MONTH", "DAY"];

export default function MainGraphLayout() {
  const { data: articles } = useFeedsControllerGetDashboardFeedsQuery();
  const [dateType, setDateType] = useState<Period>("YEAR");
  const [cryptos, setCryptos] = useState<TopCryptoDto[]>([]);
  const { socket } = useSocket();

  useEffect(() => {
    function getBestCryptos() {
      socket.emit("bestCryptos", { top: 5, period: dateType });
    }

    function onBestCryptos(cryptos: TopCryptoDto[]) {
      setCryptos(cryptos);
    }

    getBestCryptos();

    socket.on("coinmarketJobDone", getBestCryptos);
    socket.on("bestCryptos", onBestCryptos);

    return () => {
      socket.off("coinmarketJobDone", getBestCryptos);
      socket.off("bestCryptos", onBestCryptos);
    };
  }, [socket, dateType]);

  return (
    <Container>
      <CardBody className="justify-items-center">
        <List className="flex-row">
          {periodArray.map((period) => (
            <button key={period} onClick={() => setDateType(period)}>
              <label className="flex min-w-fit items-center">
                <ListItem>
                  <Radio
                    id={`period-${period}`}
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

        {cryptos && cryptos.length && <MainGraph topCryptos={cryptos} />}

        <div className="flex flex-row gap-5">
          {articles?.map((article) => (
            <ArticlePreview key={article.id} article={article} />
          ))}
        </div>
      </CardBody>
    </Container>
  );
}
