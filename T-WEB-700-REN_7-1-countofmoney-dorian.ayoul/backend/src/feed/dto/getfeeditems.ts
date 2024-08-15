import { ApiProperty } from '@nestjs/swagger';
import { IsOptional, IsString } from 'class-validator';

export class GetFeedItemsDto {
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
}
