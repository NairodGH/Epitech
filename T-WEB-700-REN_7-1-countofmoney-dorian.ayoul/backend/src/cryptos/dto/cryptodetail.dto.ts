import { ApiProperty } from '@nestjs/swagger';
import { IsBoolean, IsNumber, IsString, IsUUID } from 'class-validator';

export class CryptoDetailDto {
  @IsUUID()
  @ApiProperty({
    description: 'Id',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  id: string;

  @IsString()
  @ApiProperty({
    description: 'Name',
    example: 'Bitcoin',
  })
  name: string;

  @IsString()
  @ApiProperty({
    description: 'URL to the crypto image',
    example: 'https://assets.coingecko.com/coins/images/1/large/bitcoin.png',
  })
  imageUrl: string;

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

  @IsNumber()
  @ApiProperty({
    description: 'Id from Coinmarketcap',
    example: '1234',
  })
  coinmarketId: number;

  @IsBoolean()
  @ApiProperty({
    description: 'Is crypto available by default',
    example: true,
  })
  default: boolean;
}
