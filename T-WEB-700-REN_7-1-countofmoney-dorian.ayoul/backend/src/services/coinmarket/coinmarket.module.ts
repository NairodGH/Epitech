import { Module } from '@nestjs/common';
import { CoinMarketService } from './coinmarket.service';
import { PrismaProvider } from 'src/prisma';

@Module({
  providers: [CoinMarketService, PrismaProvider],
})
export class CoinMarketModule {}
