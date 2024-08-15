import { Inject, Injectable } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { Period, PrismaClient } from '@prisma/client';
import axios from 'axios';

// declare enum CustomCronExpression {
//   EVERY_2_MINUTES = '*/2 * * * *',
// }

@Injectable()
export class CoinMarketService {
  constructor(@Inject('Prisma') protected readonly prisma: PrismaClient) {}

  async fetchData(period: Period) {
    const response = await axios.get(
      'https://pro-api.coinmarketcap.com/v1/cryptocurrency/listings/latest?CMC_PRO_API_KEY=a42a9bf5-022e-4bc5-8224-78bfce197b53',
    );
    const prices = response.data.data.map((coin) => {
      return {
        id: coin.id,
        unitDollarPrice: coin.quote.USD.price,
        period: period,
        name: coin.name,
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
                imageUrl: '',
              },
            },
          },
        },
      });
    });
  }

  // @Cron(CronExpression.EVERY_10_SECONDS)
  // async testCron() {
  //   console.log('Calling the testCron() function');
  //   await this.fetchData(Period.MINUTE);
  // }

  @Cron('*/2 * * * *')
  async minuteCron() {
    console.log('Calling the minuteCron() function');
    await this.fetchData(Period.MINUTE);
  }

  @Cron(CronExpression.EVERY_HOUR)
  async hourCron() {
    console.log('Calling the hourCron() function');
    await this.fetchData(Period.HOUR);
  }

  @Cron(CronExpression.EVERY_DAY_AT_MIDNIGHT)
  async dayCron() {
    console.log('Calling the dayCron() function');
    await this.fetchData(Period.DAY);
  }
}
