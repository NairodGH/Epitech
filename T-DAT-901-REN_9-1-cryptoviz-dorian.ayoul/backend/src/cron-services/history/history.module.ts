import { Module } from '@nestjs/common';
import { HistoryService } from './history.service';
import { PrismaProvider } from 'src/prisma';
import { CryptosModule } from 'src/cryptos/cryptos.module';

@Module({
  imports: [CryptosModule],
  providers: [HistoryService, PrismaProvider],
})
export class HistoryModule {}
