import { Inject, Injectable } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { PrismaClient, ConstantType } from '@prisma/client';

@Injectable()
export class ConstantService {
  constructor(
    @Inject('Prisma') private readonly prisma: PrismaClient,
    private readonly jwtService: JwtService,
  ) {}

  async updateArticlesNumber(articlesNumber: number) {
    const articlesNumberRecord = await this.prisma.constant
      .findMany({
        where: {
          name: ConstantType.NB_ARTICLE,
        },
      })
      .then((res) => res[0]);

    if (articlesNumberRecord) {
      await this.prisma.constant.update({
        where: {
          id: articlesNumberRecord.id,
        },
        data: {
          value: articlesNumber,
        },
      });
    } else {
      await this.prisma.constant.create({
        data: {
          name: ConstantType.NB_ARTICLE,
          value: articlesNumber,
        },
      });
    }
  }
}
