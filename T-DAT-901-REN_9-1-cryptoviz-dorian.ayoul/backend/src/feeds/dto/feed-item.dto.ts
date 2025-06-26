import { ApiProperty } from '@nestjs/swagger';
import { IsOptional, IsString } from 'class-validator';

export class FeedItemSummaryDto {
  @IsString()
  @ApiProperty({
    description: 'Article ID',
    example: '1',
  })
  id: string;

  @IsString()
  @ApiProperty({
    description: 'Article Title',
    example: 'Bitcoin Price Prediction: BTC/USD Slumps Below $30,000',
  })
  title: string;

  @IsString()
  @IsOptional()
  @ApiProperty({
    description: 'Image URL',
    example:
      'https://www.cryptopolitan.com/wp-content/uploads/2021/07/Bitcoin-Price-Prediction-BTC-USD-Slumps-Below-30000-1.jpg',
  })
  imageUrl?: string;

  @IsString()
  @ApiProperty({
    description: 'Article date',
    example: '2021-07-20T09:00:00.000Z',
  })
  pubDate: string;

  @IsString()
  @IsOptional()
  @ApiProperty({
    description: 'Article date',
    example: '2021-07-20T09:00:00.000Z',
  })
  createdAt?: string;

  @IsString()
  @ApiProperty({
    description: 'Feed ID',
    example: '1b9d6bcd-bbfd-4b2d-9b5d-ab8dfbbd4bed',
  })
  feedId: string;
}

export class FeedItemDetailsDto extends FeedItemSummaryDto {
  @IsString()
  @ApiProperty({
    description: 'Article body',
    example:
      'Bitcoin price prediction shows BTC/USD slumping below $30,000 as the cryptocurrency market continues to bleed. The Bitcoin price is currently trading at $29,937, which is a 5.7% decrease from yesterday. The cryptocurrency market is bleeding as the bears continue to dominate the market. The market is currently down by 5.7%, with Bitcoin leading the way. The Bitcoin price prediction shows BTC/USD slumping below $30,000 as the bears continue to dominate the market. The Bitcoin price is currently trading at $29,937, which is a 5.7% decrease from yesterday. The Bitcoin price prediction shows BTC/USD slumping below $30,000 as the bears continue to dominate the market. The Bitcoin price is currently trading at $29,937, which is a 5.7% decrease from yesterday.',
  })
  content: string;

  @IsString()
  @IsOptional()
  @ApiProperty({
    description: 'Article source',
    example: 'cryptopolitan',
  })
  link?: string;
}
