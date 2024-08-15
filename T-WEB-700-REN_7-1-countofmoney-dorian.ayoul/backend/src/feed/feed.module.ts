import { Module } from '@nestjs/common';
import { FeedService } from './feed.service';
import { FeedController } from './feed.controller';
import { PrismaProvider } from 'src/prisma';
import { JwtModule } from '@nestjs/jwt';
import { JwtStrategy } from 'src/users/jwt.strategy';

@Module({
  imports: [
    JwtModule.register({
      secret: process.env.SECRET,
      signOptions: {
        expiresIn: 3600 * 24 * 30, // 30 days
      },
    }),
  ],
  controllers: [FeedController],
  providers: [FeedService, JwtStrategy, PrismaProvider],
})
export class FeedModule {}
