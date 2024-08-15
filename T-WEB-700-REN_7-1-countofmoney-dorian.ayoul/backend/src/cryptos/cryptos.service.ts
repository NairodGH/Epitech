import { Inject, Injectable } from '@nestjs/common';
import { Period, PrismaClient } from '@prisma/client';
import { UpdateCryptoDto } from './dto/updatecrypto.dto';
import { CryptoDetailDto } from './dto/cryptodetail.dto';
import { CryptoDataDto } from './dto/cryptodata.dto';
import { CryptoDto } from './dto/crypto.dto';
import { JwtService } from '@nestjs/jwt';
import { DefaultCryptoDto } from './dto/defaultcrypto.dto';

@Injectable()
export class CryptosService {
  constructor(
    @Inject('Prisma') private readonly prisma: PrismaClient,
    private readonly jwtService: JwtService,
  ) {}

  batch_size = [
    { type: Period.MINUTE, duration: 60 },
    { type: Period.HOUR, duration: 48 },
    { type: Period.DAY, duration: 60 },
  ];

  async verifyToken(token: string): Promise<boolean> {
    try {
      const decoded = this.jwtService.verify(token);
      return !!decoded;
    } catch (error) {
      return false;
    }
  }

  async getOpeningPrice(cmid: string) {
    const openingPrice = await this.prisma.cryptoValue.findFirst({
      where: {
        cryptoId: cmid,
        period: 'DAY',
      },
      select: {
        unitDollarPrice: true,
      },
      orderBy: {
        createdAt: 'desc',
      },
    });
    return openingPrice?.unitDollarPrice;
  }

  async getCurrentPrice(cmid: string) {
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
    return currentPrice.unitDollarPrice;
  }

  async getLowestPriceDay(cmid: string) {
    const dateYesterday = new Date();
    dateYesterday.setDate(dateYesterday.getDate() - 1);

    const lowestPriceDay = await this.prisma.cryptoValue.findFirst({
      where: {
        cryptoId: cmid,
        period: 'MINUTE',
        createdAt: {
          gte: dateYesterday,
        },
      },
      select: {
        unitDollarPrice: true,
      },
      orderBy: {
        unitDollarPrice: 'asc',
      },
    });
    return lowestPriceDay.unitDollarPrice;
  }

  async getHighestPriceDay(cmid: string) {
    const dateYesterday = new Date();
    dateYesterday.setDate(dateYesterday.getDate() - 1);

    const highestPriceDay = await this.prisma.cryptoValue.findFirst({
      where: {
        cryptoId: cmid,
        period: 'MINUTE',
        createdAt: {
          gte: dateYesterday,
        },
      },
      select: {
        unitDollarPrice: true,
      },
      orderBy: {
        unitDollarPrice: 'desc',
      },
    });
    return highestPriceDay.unitDollarPrice;
  }

  async getAvailableCryptos(req: any): Promise<CryptoDto[]> {
    let whereClause = {};

    if (
      !req.headers.authorization ||
      !(await this.verifyToken(req.headers.authorization.substring(7)))
    ) {
      whereClause = { default: true };
    }

    const cryptos = await this.prisma.crypto.findMany({
      select: {
        id: true,
        name: true,
        default: true,
      },
      where: whereClause,
    });
    return cryptos;
  }

  async getCryptos(cmids: string): Promise<CryptoDetailDto[]> {
    if (!cmids || cmids.length === 0) {
      return null;
    }
    const cmidArray = cmids.split(',');
    const cryptos = await this.prisma.crypto.findMany({
      where: {
        id: {
          in: cmidArray,
        },
      },
    });
    const result: CryptoDetailDto[] = [];
    for (const crypto of cryptos) {
      result.push({
        ...crypto,
        openingPrice: await this.getOpeningPrice(crypto.id),
        currentPrice: await this.getCurrentPrice(crypto.id),
        lowestPriceDay: await this.getLowestPriceDay(crypto.id),
        highestPriceDay: await this.getHighestPriceDay(crypto.id),
      });
    }
    return result;
  }

  async getCryptoById(cmid: string): Promise<CryptoDetailDto> {
    const crypto = await this.prisma.crypto.findUnique({
      where: {
        id: cmid,
      },
      select: {
        id: true,
        name: true,
        imageUrl: true,
        coinmarketId: true,
        default: true,
      },
    });
    return {
      ...crypto,
      openingPrice: await this.getOpeningPrice(crypto.id),
      currentPrice: await this.getCurrentPrice(crypto.id),
      lowestPriceDay: await this.getLowestPriceDay(crypto.id),
      highestPriceDay: await this.getHighestPriceDay(crypto.id),
    };
  }

  async getCryptoHistory(cmid: string, period: Period): Promise<CryptoDataDto> {
    const periodValue = this.batch_size.find((batch) => batch.type === period);

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
      openingPrice: await this.getOpeningPrice(cmid),
      currentPrice: await this.getCurrentPrice(cmid),
      lowestPriceDay: await this.getLowestPriceDay(cmid),
      highestPriceDay: await this.getHighestPriceDay(cmid),
      priceHistory: cryptoData.map((data) => data.unitDollarPrice),
    };
  }

  async updateCrypto(
    updateCryptoData: UpdateCryptoDto,
    cmid: string,
  ): Promise<UpdateCryptoDto> {
    const crypto = await this.prisma.crypto.update({
      where: {
        id: cmid,
      },
      data: {
        name: updateCryptoData.name,
        coinmarketId: updateCryptoData.coinmarketId,
        imageUrl: updateCryptoData.imageUrl,
        default: updateCryptoData.default,
      },
    });
    return crypto;
  }

  async deleteCrypto(cmid: string): Promise<boolean> {
    await this.prisma.crypto.delete({
      where: {
        id: cmid,
      },
    });
    await this.prisma.cryptoValue.deleteMany({
      where: {
        cryptoId: cmid,
      },
    });
    return true;
  }

  async defaultCryptos(
    defaultCryptoDto: DefaultCryptoDto,
  ): Promise<DefaultCryptoDto> {
    // set all cryptos to false except the ones in the array, which are set to true
    await this.prisma.crypto.updateMany({
      where: {
        default: true,
      },
      data: {
        default: false,
      },
    });
    await this.prisma.crypto.updateMany({
      where: {
        id: {
          in: defaultCryptoDto.cmids,
        },
      },
      data: {
        default: true,
      },
    });
    return defaultCryptoDto;
  }

  async getDashboardCryptos(req: any): Promise<CryptoDto[]> {
    const jwt = req.headers.authorization?.split(' ')[1];
    const decoded = this.jwtService.decode(jwt);
    let id: string = decoded?.id;

    if (!req.headers.authorization || !(await this.verifyToken(jwt))) {
      id = null;
    }

    if (id) {
      const user = await this.prisma.user.findUnique({
        where: {
          id: id,
        },
        select: {
          cryptos: {
            select: {
              id: true,
              name: true,
              default: true,
            },
          },
        },
      });
      return user?.cryptos as CryptoDto[];
    }

    const cryptos = await this.prisma.crypto.findMany({
      where: {
        default: true,
      },
      select: {
        id: true,
        name: true,
        default: true,
      },
    });
    return cryptos as CryptoDto[];
  }
}
