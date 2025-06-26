import CryptoCard from "@/components/molecules/CrytpoCard";
import MainGraphLayout from "@/components/organisms/MainGraphLayout";
import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import useSocket from "@/socket/socket";
import { CryptoSummaryDto, useScrapperControllerGetCryptosQuery } from "@/store/api/backendApi/endpoints/v1";
import { Spinner } from "@material-tailwind/react";
import { useEffect, useMemo, useState } from "react";

export default function Dashboard() {
  const { data: scrapping, isFetching: isScrappingLoading } = useScrapperControllerGetCryptosQuery(undefined, {
    pollingInterval: 300000,
  });

  // this list of cryptos is getted every time the cronjob is done
  const [cryptos, setCryptos] = useState<CryptoSummaryDto[]>([]);
  const { socket } = useSocket();

  useEffect(() => {
    function getCryptos() {
      socket.emit("cryptos");
    }

    function onCryptos(cryptos: CryptoSummaryDto[]) {
      setCryptos(cryptos);
    }

    getCryptos();

    socket.on("coinmarketJobDone", getCryptos);
    socket.on("cryptos", onCryptos);

    return () => {
      socket.off("coinmarketJobDone", getCryptos);
      socket.off("cryptos", onCryptos);
    };
  }, [socket]);

  const mergedCryptos = useMemo(() => {
    return cryptos?.map((crypto) => {
      const matchingScrap = scrapping?.find((scrap) => scrap.cryptoName === crypto.name);
      return {
        ...crypto,
        scrapping: matchingScrap || undefined,
      };
    });
  }, [cryptos, scrapping]);

  return (
    <main>
      <PageWrapper>
        <div className="flex flex-col justify-start gap-5">
          <MainGraphLayout />
            <div className="grid grid-flow-row grid-cols-4 gap-5">
            {mergedCryptos
              ?.filter((crypto) => crypto.scrapping != null)
              .map((crypto) => (
                <CryptoCard key={crypto.id} crypto={crypto} scrapping={crypto.scrapping} />
              ))}

            {(!cryptos || isScrappingLoading) && (
              <Container>
                <div className="flex flex-row justify-center p-10">
                  <Spinner className="h-16 w-16" color="gray" />
                </div>
              </Container>
            )}
          </div>
        </div>
      </PageWrapper>
    </main>
  );
}
