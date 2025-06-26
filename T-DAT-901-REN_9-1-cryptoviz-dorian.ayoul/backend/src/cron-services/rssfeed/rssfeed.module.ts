import { Module } from '@nestjs/common';
import { RSSfeedService } from './rssfeed.service';
import { PrismaProvider } from 'src/prisma';

@Module({
  providers: [RSSfeedService, PrismaProvider],
})
export class RSSfeedModule {}
