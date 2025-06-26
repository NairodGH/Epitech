import { Inject, Injectable, Logger } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { CryptoValue, PrismaClient } from '@prisma/client';
import { CryptosGateway } from 'src/cryptos/cryptos.gateway';
import { DayValueDto } from './dto/day-value.dto';

@Injectable()
export class HistoryService {
  private readonly logger = new Logger(HistoryService.name);

  constructor(
    @Inject('Prisma') protected readonly prisma: PrismaClient,
    private readonly cryptosGateway: CryptosGateway,
  ) {}

  private async InsertDayValues(values: DayValueDto[]) {
    for (const value of values) {
      const exists = await this.prisma.cryptoDay.findFirst({
        where: {
          cryptoId: value.cryptoId,
          date: value.date,
        },
      });

      if (!exists) {
        await this.prisma.cryptoDay.create({
          data: value,
        });
      } else {
        await this.prisma.cryptoDay.update({
          where: {
            id: exists.id,
          },
          data: value,
        });
      }
    }
  }

  private async CalcDaysHistory(days: { [key: string]: CryptoValue[] }) {
    const toInsert: DayValueDto[] = [];

    for (const day in days) {
      const values = days[day];

      const highest = values.reduce((prev, current) => {
        return prev.unitDollarPrice > current.unitDollarPrice ? prev : current;
      });
      const lowest = values.reduce((prev, current) => {
        return prev.unitDollarPrice < current.unitDollarPrice ? prev : current;
      });

      toInsert.push({
        cryptoId: values[0].cryptoId,
        date: new Date(day),
        openingPrice: values[0].unitDollarPrice,
        closingPrice: values[values.length - 1].unitDollarPrice,
        highPrice: highest.unitDollarPrice,
        lowPrice: lowest.unitDollarPrice,
      });
    }

    this.InsertDayValues(toInsert);
  }

  private async GetDaysValues(values: CryptoValue[]) {
    const days: { [key: string]: CryptoValue[] } = {};

    for (const value of values) {
      const date = value.createdAt.toISOString().slice(0, 10);

      if (!days[date]) {
        days[date] = [];
      }

      days[date].push(value);
    }

    return days;
  }

  private async CalcHistory() {
    const data = await this.prisma.crypto.findMany();

    for (const crypto of data) {
      const values = await this.prisma.cryptoValue.findMany({
        where: {
          cryptoId: crypto.id,
        },
        orderBy: {
          createdAt: 'desc',
        },
      });
      const days = await this.GetDaysValues(values);

      await this.CalcDaysHistory(days);
    }
  }

  @Cron(CronExpression.EVERY_10_SECONDS)
  async dayCron() {
    this.logger.log('Calculating history...');
    await this.CalcHistory();
    this.cryptosGateway.emitCandlestickJobDone();
    this.logger.log('History calculated');
  }
}
