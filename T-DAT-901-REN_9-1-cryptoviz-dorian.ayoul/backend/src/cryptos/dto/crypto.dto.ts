import { ApiProperty } from '@nestjs/swagger';
import { IsArray, IsNumber, IsString, IsUUID } from 'class-validator';

export class CryptoSummaryDto {
  @IsUUID()
  @ApiProperty({
    description: 'Id',
    example: '12663a62-a985-409a-bcbc-ee4253d4ea8e',
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
    description: 'Symbol',
    example: 'BTC',
  })
  symbol: string;

  @IsString()
  @ApiProperty({
    description: 'URL to the crypto image',
    example: 'https://assets.coingecko.com/coins/images/1/large/bitcoin.png',
  })
  imageUrl: string;

  @IsString()
  @ApiProperty({
    description: 'Description',
    example:
      'Bitcoin is a decentralized digital currency, without a central bank or single administrator, that can be sent from user to user on the peer-to-peer bitcoin network without the need for intermediaries.',
  })
  description: string;
}

export class CryptoDetailsDto extends CryptoSummaryDto {
  @IsNumber()
  @ApiProperty({
    description: 'Current price',
    example: 10000,
  })
  currentPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'Lowest price of the batch',
    example: 8000,
  })
  lowestPriceBatch: number;

  @IsNumber()
  @ApiProperty({
    description: 'Highest price of the batch',
    example: 11000,
  })
  highestPriceBatch: number;

  @IsNumber()
  @ApiProperty({
    description: 'Id from Coinmarketcap',
    example: '1234',
  })
  coinmarketId: number;
}

class TopCryptoValue {
  @IsNumber()
  @ApiProperty({
    description: 'Value',
    example: 10000,
  })
  value: number;

  @IsString()
  @ApiProperty({
    description: 'Date',
    example: '2021-08-25T10:00:00.000Z',
  })
  createdAt: Date;
}

export class TopCryptoDto extends CryptoSummaryDto {
  @IsArray()
  @ApiProperty({
    description: 'Top crypto values',
    example: [12, 232, 21],
    type: [TopCryptoValue],
  })
  price: TopCryptoValue[];
}
