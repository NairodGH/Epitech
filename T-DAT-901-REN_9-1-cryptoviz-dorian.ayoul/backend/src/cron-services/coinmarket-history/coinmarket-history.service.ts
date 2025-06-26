import { Inject, Injectable, Logger } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { PrismaClient } from '@prisma/client';
import { readFileSync } from 'fs';
import { CryptosGateway } from 'src/cryptos/cryptos.gateway';

type FileType = {
  stats: [number, number];
};

@Injectable()
export class CoinMarketHistoryService {
  private readonly logger = new Logger(CoinMarketHistoryService.name);

  constructor(
    @Inject('Prisma') protected readonly prisma: PrismaClient,
    private readonly cryptosGateway: CryptosGateway,
  ) {}

  private async getData() {
    const monero = await this.prisma.crypto.findFirst({
      where: {
        name: 'Monero',
      },
    });

    if (!monero) {
      this.logger.error('monero not found');
      return;
    }

    const file = readFileSync(
      'src/cron-services/coinmarket-history/LTC_year.json',
      'utf8',
    );

    const data = JSON.parse(file) as FileType;

    for (const minute of data['stats']) {
      await this.prisma.cryptoValue.create({
        data: {
          cryptoId: monero.id,
          unitDollarPrice: minute[1],
          period: 'DAY',
          createdAt: new Date(minute[0]),
        },
      });
    }
  }

  //   @Cron(CronExpression.EVERY_10_SECONDS)
  //   async monthCron() {
  //     this.logger.log('Running cron job');
  //     await this.getData();
  //   }
}
