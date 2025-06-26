import { Inject, Injectable, Logger } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { Period, PrismaClient } from '@prisma/client';
import axios from 'axios';
import { CryptosGateway } from 'src/cryptos/cryptos.gateway';

@Injectable()
export class CoinMarketService {
  private readonly logger = new Logger(CoinMarketService.name);

  constructor(
    @Inject('Prisma') protected readonly prisma: PrismaClient,
    private readonly cryptosGateway: CryptosGateway,
  ) {}

  private async fetchCryptoList() {
    const ids = await this.prisma.crypto
      .findMany({
        select: {
          coinmarketId: true,
        },
      })
      .then((res) => res.map((coin) => coin.coinmarketId).join(','));
    const aux = 'logo,description';
    const url = `${process.env.COINMARKET_API_URL}/v2/cryptocurrency/info?CMC_PRO_API_KEY=${process.env.COINMARKET_API_KEY}&id=${ids}&aux=${aux}`;

    const response = await axios.get(url);

    const data = Object.values(response.data.data).map((coin: any) => {
      return {
        id: coin.id,
        imageUrl: coin.logo,
        description: coin.description,
      };
    });

    data.map(async (coin) => {
      await this.prisma.crypto.update({
        where: {
          coinmarketId: coin.id,
        },
        data: {
          imageUrl: coin.imageUrl,
          description: coin.description,
        },
      });
    });
  }

  private async fetchData(period: Period) {
    const response = await axios.get(
      `${process.env.COINMARKET_API_URL}/v1/cryptocurrency/listings/latest?CMC_PRO_API_KEY=${process.env.COINMARKET_API_KEY}`,
    );
    const prices = response.data.data.map((coin) => {
      return {
        id: coin.id,
        unitDollarPrice: coin.quote.USD.price,
        period: period,
        name: coin.name,
        symbol: coin.symbol,
      };
    });

    prices.map(async (price) => {
      await this.prisma.cryptoValue.create({
        data: {
          period: price.period,
          unitDollarPrice: price.unitDollarPrice,
          crypto: {
            connectOrCreate: {
              where: { coinmarketId: price.id },
              create: {
                coinmarketId: price.id,
                name: price.name,
                symbol: price.symbol,
              },
            },
          },
        },
      });
    });
  }

  @Cron(CronExpression.EVERY_MINUTE)
  async minuteCron() {
    this.logger.log('Fetching data from CoinMarketCap API for minute period');
    await this.fetchData(Period.MINUTE);
    await this.fetchCryptoList();
    this.cryptosGateway.emitCoinmarketJobDone();
  }

  @Cron(CronExpression.EVERY_HOUR)
  async hourCron() {
    this.logger.log('Fetching data from CoinMarketCap API for hour period');
    await this.fetchData(Period.HOUR);
    await this.fetchCryptoList();
    this.cryptosGateway.emitCoinmarketJobDone();
  }

  @Cron(CronExpression.EVERY_DAY_AT_MIDNIGHT)
  async dayCron() {
    this.logger.log('Fetching data from CoinMarketCap API for day period');
    await this.fetchData(Period.DAY);
    await this.fetchCryptoList();
    this.cryptosGateway.emitCoinmarketJobDone();
  }
}
