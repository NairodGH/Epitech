import { Module } from '@nestjs/common';
import { CryptosController } from './cryptos.controller';
import { CryptosService } from './cryptos.service';
import { PrismaProvider } from 'src/prisma';
import { JwtStrategy } from 'src/users/jwt.strategy';
import { JwtModule } from '@nestjs/jwt';

@Module({
  imports: [
    JwtModule.register({
      secret: process.env.SECRET,
      signOptions: {
        expiresIn: 3600 * 24 * 30, // 30 days
      },
    }),
  ],
  controllers: [CryptosController],
  providers: [CryptosService, JwtStrategy, PrismaProvider],
})
export class CryptosModule {}
