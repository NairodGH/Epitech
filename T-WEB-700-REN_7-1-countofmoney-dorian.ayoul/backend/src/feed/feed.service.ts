import { Inject, Injectable } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import { PrismaClient } from '@prisma/client';
import { CreateFeedDto } from './dto/createfeed';

@Injectable()
export class FeedService {
  constructor(
    @Inject('Prisma') private readonly prisma: PrismaClient,
    private readonly jwtService: JwtService,
  ) {}

  async addFeed(feed: CreateFeedDto) {
    const newFeed = await this.prisma.rSSFeed.create({
      data: feed,
    });

    return newFeed;
  }

  async getById(id: string) {
    const feed = await this.prisma.rSSFeed.findUnique({
      where: {
        id,
      },
    });

    return feed;
  }

  async getAll() {
    const feeds = await this.prisma.rSSFeed.findMany({
      select: {
        id: true,
        name: true,
      },
    });

    return feeds;
  }

  async getKeywords(id?: string) {
    if (!id) {
      return null;
    }

    const keywords = await this.prisma.user.findUnique({
      where: {
        id,
      },
      select: {
        keywords: true,
      },
    });
    const transformedKeywords = keywords.keywords.join(' | ');

    return transformedKeywords;
  }

  async getItems(req: any) {
    const number =
      (await this.prisma.constant
        .findMany({
          where: {
            name: 'NB_ARTICLE',
          },
        })
        .then((res) => res[0].value)) ?? 10;
    const userKeywords = await this.getKeywords(req.user?.id);

    if (userKeywords) {
      const feeds = await this.prisma.rSSFeedItem.findMany({
        take: number,
        orderBy: {
          createdAt: 'desc',
        },
        where: {
          OR: [
            {
              title: {
                search: userKeywords,
              },
            },
            {
              content: {
                search: userKeywords,
              },
            },
          ],
        },

        select: {
          id: true,
          title: true,
          imageUrl: true,
        },
      });

      return feeds;
    }

    const feeds = await this.prisma.rSSFeedItem.findMany({
      take: number,
      orderBy: {
        createdAt: 'desc',
      },
      select: {
        id: true,
        title: true,
        imageUrl: true,
      },
    });
    return feeds;
  }

  async getItemById(id: string) {
    const feed = await this.prisma.rSSFeedItem.findUnique({
      where: {
        id,
      },
    });

    return feed;
  }
}
