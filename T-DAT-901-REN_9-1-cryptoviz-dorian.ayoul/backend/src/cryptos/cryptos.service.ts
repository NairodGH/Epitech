import { Inject, Injectable } from '@nestjs/common';
import { CryptoValue, Period, PrismaClient } from '@prisma/client';
import { CryptoDataDto } from './dto/crypto-data.dto';
import {
  CryptoDetailsDto,
  CryptoSummaryDto,
  TopCryptoDto,
} from './dto/crypto.dto';
import { CryptoCandlestickDto } from './dto/crypto-candlestick.dto';

@Injectable()
export class CryptosService {
  constructor(@Inject('Prisma') private readonly prisma: PrismaClient) {}

  batchSize = [
    { type: Period.MINUTE, duration: 60 },
    { type: Period.HOUR, duration: 48 },
    { type: Period.DAY, duration: 60 },
  ];

  private async getCurrentPrice(cmid: string) {
    const currentPrice = await this.prisma.cryptoValue.findFirst({
      where: {
        cryptoId: cmid,
        period: 'MINUTE',
      },
      select: {
        unitDollarPrice: true,
      },
      orderBy: {
        createdAt: 'desc',
      },
    });
    if (!currentPrice) {
      return null;
    }
    return currentPrice.unitDollarPrice;
  }

  private async getLowestPriceBatch(values: CryptoValue[]) {
    if (values.length === 0) {
      return null;
    }

    return values.reduce((prev, current) => {
      return prev.unitDollarPrice < current.unitDollarPrice ? prev : current;
    }).unitDollarPrice;
  }

  private async getHighestPriceBatch(values: CryptoValue[]) {
    if (values.length === 0) {
      return null;
    }

    return values.reduce((prev, current) => {
      return prev.unitDollarPrice > current.unitDollarPrice ? prev : current;
    }).unitDollarPrice;
  }

  async getCryptos(): Promise<CryptoSummaryDto[]> {
    const cryptos = await this.prisma.crypto.findMany({
      select: {
        id: true,
        name: true,
        symbol: true,
        description: true,
        imageUrl: true,
        coinmarketId: true,
      },
    });

    cryptos.sort((a, b) => {
      return a.coinmarketId - b.coinmarketId;
    });

    cryptos.forEach((crypto) => {
      delete crypto.coinmarketId;
    });

    return cryptos as CryptoSummaryDto[];
  }

  async getCryptoById(cmid: string): Promise<CryptoDetailsDto> {
    const crypto = await this.prisma.crypto.findUnique({
      where: {
        id: cmid,
      },
      select: {
        id: true,
        name: true,
        symbol: true,
        description: true,
        imageUrl: true,
        coinmarketId: true,
        price: {
          orderBy: {
            createdAt: 'desc',
          },
        },
      },
    });

    return {
      ...crypto,
      currentPrice: await this.getCurrentPrice(crypto.id),
      lowestPriceBatch: await this.getLowestPriceBatch(crypto.price),
      highestPriceBatch: await this.getHighestPriceBatch(crypto.price),
    };
  }

  async getCryptoHistory(cmid: string, period: Period): Promise<CryptoDataDto> {
    const periodValue = this.batchSize.find((batch) => batch.type === period);

    if (!periodValue) {
      return null;
    }
    const cryptoData = await this.prisma.cryptoValue.findMany({
      where: {
        cryptoId: cmid,
        period: period,
      },
      take: periodValue.duration,
      orderBy: {
        createdAt: 'desc',
      },
    });
    return {
      id: cmid,
      currentPrice: await this.getCurrentPrice(cmid),
      lowestPriceBatch: await this.getLowestPriceBatch(cryptoData),
      highestPriceBatch: await this.getHighestPriceBatch(cryptoData),
      priceHistory: cryptoData.map((data) => data.unitDollarPrice),
    };
  }

  private async getYearCryptoData(cmid: string) {
    const cryptoData = await this.prisma.cryptoValue.findMany({
      where: {
        cryptoId: cmid,
        createdAt: {
          gt: new Date(new Date().getTime() - 24 * 60 * 60 * 1000 * 365),
        },
      },
      orderBy: {
        createdAt: 'desc',
      },
    });

    // keep only one value per day
    const uniqueDates = new Set<string>();

    return cryptoData.filter((data) => {
      const date = data.createdAt.toDateString();
      if (uniqueDates.has(date)) {
        return false;
      }
      uniqueDates.add(date);
      return true;
    });
  }

  private async getMonthCryptoData(cmid: string) {
    const cryptoData = await this.prisma.cryptoValue.findMany({
      where: {
        cryptoId: cmid,
        createdAt: {
          gt: new Date(new Date().getTime() - 24 * 60 * 60 * 1000 * 30),
        },
      },
      orderBy: {
        createdAt: 'desc',
      },
    });

    return cryptoData;
  }

  private async getDayCryptoData(cmid: string) {
    const cryptoData = await this.prisma.cryptoValue.findMany({
      where: {
        cryptoId: cmid,
        createdAt: {
          gt: new Date(new Date().getTime() - 24 * 60 * 60 * 1000),
        },
      },
      orderBy: {
        createdAt: 'desc',
      },
    });

    return cryptoData;
  }

  async getTopCryptos(
    top = 10,
    period: 'YEAR' | 'MONTH' | 'DAY',
  ): Promise<TopCryptoDto[]> {
    const cryptos = await this.prisma.crypto.findMany({
      select: {
        id: true,
        name: true,
        symbol: true,
        description: true,
        imageUrl: true,
        coinmarketId: true,
      },
      orderBy: {
        coinmarketId: 'asc',
      },
      take: top,
    });

    cryptos.forEach((crypto) => {
      delete crypto.coinmarketId;
    });

    const res: TopCryptoDto[] = [];

    for (const crypto of cryptos) {
      if (period === 'YEAR') {
        res.push({
          ...crypto,
          price: await this.getYearCryptoData(crypto.id).then((data) =>
            data.map((price) => ({
              value: price.unitDollarPrice,
              createdAt: price.createdAt,
            })),
          ),
        });
      }

      if (period === 'MONTH') {
        res.push({
          ...crypto,
          price: await this.getMonthCryptoData(crypto.id).then((data) =>
            data.map((price) => ({
              value: price.unitDollarPrice,
              createdAt: price.createdAt,
            })),
          ),
        });
      }

      if (period === 'DAY') {
        res.push({
          ...crypto,
          price: await this.getDayCryptoData(crypto.id).then((data) =>
            data.map((price) => ({
              value: price.unitDollarPrice,
              createdAt: price.createdAt,
            })),
          ),
        });
      }
    }

    return res;
  }

  async getCryptoCandlestick(cmid: string): Promise<CryptoCandlestickDto> {
    const cryptoData = await this.prisma.cryptoDay.findMany({
      where: {
        cryptoId: cmid,
      },
      take: this.batchSize.find((batch) => batch.type === Period.DAY).duration,
      orderBy: {
        createdAt: 'desc',
      },
    });

    const candlestick: CryptoCandlestickDto = {
      id: cmid,
      candlestickValues: cryptoData.map((data) => ({
        id: data.id,
        date: data.date,
        openingPrice: data.openingPrice,
        closingPrice: data.closingPrice,
        highPrice: data.highPrice,
        lowPrice: data.lowPrice,
      })),
    };

    return candlestick;
  }
}
