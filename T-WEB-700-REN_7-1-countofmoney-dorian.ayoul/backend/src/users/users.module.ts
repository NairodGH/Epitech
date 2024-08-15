import { Module } from '@nestjs/common';
import { UsersController } from './users.controller';
import { PassportModule } from '@nestjs/passport';
import { JwtModule } from '@nestjs/jwt';
import { UsersService } from './users.service';
import { JwtStrategy } from './jwt.strategy';
import { PrismaProvider } from 'src/prisma';

@Module({
  imports: [
    PassportModule,
    JwtModule.register({
      secret: process.env.SECRET,
      signOptions: {
        expiresIn: 3600 * 24 * 30, // 30 days
      },
    }),
  ],
  controllers: [UsersController],
  providers: [UsersService, JwtStrategy, PrismaProvider],
})
export class UsersModule {}
