import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { PrismaProvider } from './prisma';
import { CryptosModule } from './cryptos/cryptos.module';
import { CoinMarketModule } from './cron-services/coinmarket/coinmarket.module';
import { ScheduleModule } from '@nestjs/schedule';
import { RSSfeedModule } from './cron-services/rssfeed/rssfeed.module';
import { FeedsModule } from './feeds/feeds.module';
import { HistoryModule } from './cron-services/history/history.module';
import { ScrapperModule } from './scrapper/scrapper.module';
import { CoinMarketHistoryModule } from './cron-services/coinmarket-history/coinmarket-history.module';

@Module({
  imports: [
    CryptosModule,
    ScheduleModule.forRoot(),
    CoinMarketModule,
    RSSfeedModule,
    FeedsModule,
    HistoryModule,
    ScrapperModule,
    CoinMarketHistoryModule,
  ],
  controllers: [AppController],
  providers: [AppService, PrismaProvider],
})
export class AppModule {}
