import { Module } from '@nestjs/common';
import { FeedsController } from './feeds.controller';
import { FeedsService } from './feeds.service';
import { PrismaProvider } from 'src/prisma';

@Module({
  controllers: [FeedsController],
  providers: [FeedsService, PrismaProvider],
})
export class FeedsModule {}
