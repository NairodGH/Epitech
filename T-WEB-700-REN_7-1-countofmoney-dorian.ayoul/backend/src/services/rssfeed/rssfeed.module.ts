import { Module } from '@nestjs/common';
import { RSSFeedService } from './rssfeed.service';
import { PrismaProvider } from 'src/prisma';

@Module({
  providers: [RSSFeedService, PrismaProvider],
})
export class RSSFeedModule {}
