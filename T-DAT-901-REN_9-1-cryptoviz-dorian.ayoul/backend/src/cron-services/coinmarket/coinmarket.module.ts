import { Module } from '@nestjs/common';
import { CoinMarketService } from './coinmarket.service';
import { PrismaProvider } from 'src/prisma';
import { CryptosModule } from 'src/cryptos/cryptos.module';

@Module({
  imports: [CryptosModule],
  providers: [CoinMarketService, PrismaProvider],
})
export class CoinMarketModule {}
