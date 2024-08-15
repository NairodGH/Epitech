import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { UsersModule } from './users/users.module';
import { PrismaProvider } from './prisma';
import { CryptosModule } from './cryptos/cryptos.module';
import { CoinMarketModule } from './services/coinmarket/coinmarket.module';
import { ScheduleModule } from '@nestjs/schedule';
import { RSSFeedModule } from './services/rssfeed/rssfeed.module';
import { FeedModule } from './feed/feed.module';
import { ConstantModule } from './constant/constant.module';

@Module({
  imports: [
    UsersModule,
    CryptosModule,
    FeedModule,
    ConstantModule,
    ScheduleModule.forRoot(),
    CoinMarketModule,
    RSSFeedModule,
  ],
  controllers: [AppController],
  providers: [AppService, PrismaProvider],
})
export class AppModule {}
