import { Module } from '@nestjs/common';
import { CryptosController } from './cryptos.controller';
import { CryptosService } from './cryptos.service';
import { PrismaProvider } from 'src/prisma';
import { CryptosGateway } from './cryptos.gateway';

@Module({
  imports: [],
  controllers: [CryptosController],
  providers: [CryptosService, PrismaProvider, CryptosGateway],
  exports: [CryptosService, CryptosGateway],
})
export class CryptosModule {}
