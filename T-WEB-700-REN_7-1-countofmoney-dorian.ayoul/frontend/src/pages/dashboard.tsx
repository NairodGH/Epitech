import CryptoGraph from "@/components/organisms/CryptoGraph";
import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import { useCryptosControllerGetDashboardCryptosQuery } from "@/store/api/backendApi/endpoints/v1";
import { Spinner } from "@material-tailwind/react";
import { useEffect, useState } from "react";

export default function Dashboard() {
  const [isLoading, setIsLoading] = useState(false);

  const { data: cryptos, isLoading: isGetCryptosLoading } =
    useCryptosControllerGetDashboardCryptosQuery();

  useEffect(() => {
    setIsLoading(isGetCryptosLoading);
  }, [isGetCryptosLoading]);

  return (
    <main>
      <PageWrapper>
        <div className="grid grid-flow-row gap-10">
          {cryptos?.map((crypto) => (
            <CryptoGraph key={crypto.id} id={crypto.id} name={crypto.name} />
          ))}
          {isLoading && (
            <Container>
              <div className="flex flex-row justify-center p-10">
                <Spinner className="h-16 w-16" color="gray" />
              </div>
            </Container>
          )}
        </div>
      </PageWrapper>
    </main>
  );
}
