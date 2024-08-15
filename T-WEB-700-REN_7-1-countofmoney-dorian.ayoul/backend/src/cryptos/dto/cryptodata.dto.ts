import { ApiProperty } from '@nestjs/swagger';
import { IsArray, IsNumber, IsUUID } from 'class-validator';

export class CryptoDataDto {
  @IsUUID()
  @ApiProperty({
    description: 'Id',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  id: string;

  @IsNumber()
  @ApiProperty({
    description: 'Current price',
    example: 10000,
  })
  currentPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'Opening price',
    example: 9000,
  })
  openingPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'Lowest price of the day',
    example: 8000,
  })
  lowestPriceDay: number;

  @IsNumber()
  @ApiProperty({
    description: 'Highest price of the day',
    example: 11000,
  })
  highestPriceDay: number;

  @IsArray()
  @ApiProperty({
    description: 'Price history depending on the period',
    example: [10000, 9000, 8000, 11000],
  })
  priceHistory: number[];
}
