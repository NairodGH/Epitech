import { Module } from '@nestjs/common';
import { PrismaProvider } from 'src/prisma';
import { JwtModule } from '@nestjs/jwt';
import { JwtStrategy } from 'src/users/jwt.strategy';
import { ConstantController } from './constant.controller';
import { ConstantService } from './constant.service';

@Module({
  imports: [
    JwtModule.register({
      secret: process.env.SECRET,
      signOptions: {
        expiresIn: 3600 * 24 * 30, // 30 days
      },
    }),
  ],
  controllers: [ConstantController],
  providers: [ConstantService, JwtStrategy, PrismaProvider],
})
export class ConstantModule {}
