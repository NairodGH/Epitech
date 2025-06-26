import { Inject, Injectable } from '@nestjs/common';
import { PrismaClient } from '@prisma/client';

@Injectable()
export class FeedsService {
  constructor(@Inject('Prisma') protected readonly prisma: PrismaClient) {}

  async getFeedsProviders() {
    return this.prisma.rSSFeed.findMany();
  }

  async getFeedsCount() {
    return this.prisma.rSSFeedItem.count();
  }

  async getNFeedsWithOffset(n: number, offset: number) {
    return this.prisma.rSSFeedItem.findMany({
      take: n,
      skip: offset,
      orderBy: {
        pubDate: 'desc',
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
        pubDate: true,
        createdAt: true,
        feedId: true,
      },
    });
  }

  async getNFeedsWithOffsetByFeedId(n: number, offset: number, feedId: string) {
    return this.prisma.rSSFeedItem.findMany({
      take: n,
      skip: offset,
      where: {
        feedId,
      },
      orderBy: {
        pubDate: 'desc',
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
        pubDate: true,
        createdAt: true,
        feedId: true,
      },
    });
  }

  async getFeedsByPeriod(startDate: Date, endDate: Date) {
    return this.prisma.rSSFeedItem.findMany({
      where: {
        pubDate: {
          gte: startDate,
          lte: endDate,
        },
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
        pubDate: true,
        createdAt: true,
        feedId: true,
      },
    });
  }

  async getFeedsByPeriodAndFeedId(
    startDate: Date,
    endDate: Date,
    feedId: string,
  ) {
    return this.prisma.rSSFeedItem.findMany({
      where: {
        pubDate: {
          gte: startDate,
          lte: endDate,
        },
        feedId,
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
        pubDate: true,
        createdAt: true,
        feedId: true,
      },
    });
  }

  async getDashboardFeeds() {
    return this.prisma.rSSFeedItem.findMany({
      where: {
        pubDate: {
          gte: new Date(new Date().setHours(0, 0, 0, 0) - 24 * 60 * 60 * 1000),
          lte: new Date(new Date().setHours(0, 0, 0, 0)),
        },
      },
      take: 10,
      orderBy: {
        pubDate: 'desc',
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
        pubDate: true,
        createdAt: true,
        feedId: true,
      },
    });
  }

  async getById(id: string) {
    return this.prisma.rSSFeedItem.findUnique({
      where: {
        id,
      },
    });
  }
}
