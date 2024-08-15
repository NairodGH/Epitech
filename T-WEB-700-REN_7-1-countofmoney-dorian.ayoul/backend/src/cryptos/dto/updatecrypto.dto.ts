import { ApiProperty } from '@nestjs/swagger';
import { IsBoolean, IsNumber, IsString } from 'class-validator';

export class UpdateCryptoDto {
  @IsString()
  @ApiProperty({
    description: 'Name',
    example: 'Bitcoin',
  })
  name: string;

  @IsNumber()
  @ApiProperty({
    description: 'Id from Coinmarketcap',
    example: '1234',
  })
  coinmarketId: number;

  @IsString()
  @ApiProperty({
    description: 'URL to the crypto image',
    example: 'https://assets.coingecko.com/coins/images/1/large/bitcoin.png',
  })
  imageUrl: string;

  @IsBoolean()
  @ApiProperty({
    description: 'Is crypto available by default',
    example: true,
  })
  default: boolean;
}
