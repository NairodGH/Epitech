import { Inject, Injectable } from '@nestjs/common';
import { Cron, CronExpression } from '@nestjs/schedule';
import { PrismaClient } from '@prisma/client';
import axios from 'axios';
import * as xml2js from 'xml2js';

@Injectable()
export class RSSFeedService {
  constructor(@Inject('Prisma') protected readonly prisma: PrismaClient) {}

  async fetchData() {
    const feeds = await this.prisma.rSSFeed.findMany();

    feeds.forEach(async (feed) => {
      const rssSource = feed.link;

      const promise = axios.get(rssSource);
      const response = await promise;

      const rssData = response.data;

      const parser = new xml2js.Parser({ trim: false, normalize: true });
      const data = await parser.parseStringPromise(rssData);

      const rssItemsToSave = data.rss.channel[0].item.map((item) => {
        return {
          title: item.title[0],
          content: item.description.join(''),
          feedId: feed.id,
        };
      });
      for (const item of rssItemsToSave) {
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
  }

  //   @Cron(CronExpression.EVERY_10_SECONDS)
  //   async hourCron() {
  //     console.log('Testing press articles');
  //     await this.fetchData();
  //     console.log('Done testing press articles');
  //   }

  @Cron(CronExpression.EVERY_6_HOURS)
  async dayCron() {
    console.log('Updating press articles');
    await this.fetchData();
  }
}
