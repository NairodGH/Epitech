import { Module } from '@nestjs/common';
import { CoinMarketHistoryService } from './coinmarket-history.service';
import { PrismaProvider } from 'src/prisma';
import { CryptosModule } from 'src/cryptos/cryptos.module';

@Module({
  imports: [CryptosModule],
  providers: [CoinMarketHistoryService, PrismaProvider],
})
export class CoinMarketHistoryModule {}
