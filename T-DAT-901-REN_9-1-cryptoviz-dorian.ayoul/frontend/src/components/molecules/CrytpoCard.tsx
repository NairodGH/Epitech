import { CryptoSummaryDto, ScrapperDto } from "@/store/api/backendApi/endpoints/v1";
import { Card, CardBody, Typography } from "@material-tailwind/react";
import Image from "next/image";
import Link from "next/link";

type CryptoCardProps = {
  crypto: CryptoSummaryDto;
  scrapping?: ScrapperDto;
};

export default function CryptoCard({ crypto, scrapping }: CryptoCardProps) {
  const { id, name, imageUrl } = crypto;
  const { price, last24h, vol24h } = scrapping || {};

  return (
    <Link href={`/cryptos/${id}`}>
      <Card className="cursor-pointer transition hover:shadow-lg hover:scale-105">
        <CardBody className="flex flex-col">
          <div className="flex flex-row justify-between items-end">
            <Typography variant="h5" color="blue-gray" className="mb-4 font-normal text-2xl truncate">
              {name || "N/A"}
            </Typography>
            {imageUrl && (
              <Image src={imageUrl} alt={`${name}-image`} className="mb-4 h-12 w-12" width={100} height={100} />
            )}
          </div>

          <Typography variant="h5" color="blue-gray" className=" font-large text-3xl">
            {price || "N/A"}
          </Typography>
          <Typography variant="h5" color="blue-gray" className="mb-2 font-normal text-base">
            Volume 24h: {vol24h || "N/A"}
          </Typography>
          <Typography variant="h5" color="blue-gray" className="mb-2 font-normal text-base">
            24h evolution:
          </Typography>
          <Typography
            variant="h5"
            color="blue-gray"
            className="font-large text-2xl p-2 w-24 text-center rounded-full"
            style={{
              backgroundColor: last24h ? (parseFloat(last24h) >= 0 ? "#82C46C" : "#F08080") : "grey",
            }}
          >
            {last24h || "N/A"}
          </Typography>
        </CardBody>
      </Card>
    </Link>
  );
}
