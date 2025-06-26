import { Inject, Injectable, Logger } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { PrismaClient } from '@prisma/client';
import axios from 'axios';
import { Parser } from 'xml2js';

@Injectable()
export class RSSfeedService {
  private readonly logger = new Logger(RSSfeedService.name);

  constructor(@Inject('Prisma') protected readonly prisma: PrismaClient) {}

  private async addNewFeeds() {
    const envFeeds = process.env.RSS_FEEDS_URLS.split(',');

    await this.prisma.rSSFeed.createMany({
      data: envFeeds.map((feed) => {
        const name = feed
          .split('/')
          .pop()
          .replace(/[-.]/g, ' ')
          .replace(/\b\w/g, (l) => l.toUpperCase());

        return {
          name,
          link: feed,
        };
      }),
      skipDuplicates: true,
    });
  }

  private removeImagesFromContent(content: string): string {
    return content.replace(/<img[^>]*>/g, ''); // Supprime toutes les balises <img>
  }

  async fetchData() {
    await this.addNewFeeds();

    const feeds = await this.prisma.rSSFeed.findMany();

    const allItems = [];

    feeds.forEach(async (feed) => {
      const rssSource = feed.link;
      const response = await axios.get<string>(rssSource);

      const rssData = response.data;

      const parser = new Parser({ trim: false, normalize: true });
      const data = await parser.parseStringPromise(rssData);

      const rssItems = data.rss.channel[0].item.map((item) => {
        const content = Array.isArray(item['content:encoded'])
          ? item['content:encoded'].join('')
          : item['content:encoded'];

        const cleanedContent = this.removeImagesFromContent(content);

        return {
          title: item.title[0],
          content: cleanedContent,
          pubDate: new Date(item.pubDate[0]),
          feedId: feed.id,
        };
      });

      for (const item of rssItems) {
        const existingItem = await this.prisma.rSSFeedItem.findFirst({
          where: {
            title: item.title,
            content: item.content,
            feedId: item.feedId,
          },
        });

        if (!existingItem) {
          await this.prisma.rSSFeedItem.create({
            data: item,
          });
        }
      }
    });

    return allItems;
  }

  async getRssItemsWithContent() {
    return await this.fetchData();
  }

  @Cron(CronExpression.EVERY_10_HOURS)
  async dayCron() {
    this.logger.log('Fetching RSS feeds');
    await this.fetchData(); // Exécution périodique pour actualiser les données si nécessaire
  }
}
