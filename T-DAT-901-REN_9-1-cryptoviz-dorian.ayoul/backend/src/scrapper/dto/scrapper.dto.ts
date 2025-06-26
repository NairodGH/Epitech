import { ApiProperty } from '@nestjs/swagger';
import { IsString } from 'class-validator';

export class ScrapperDto {
  @IsString()
  @ApiProperty({
    description: 'Crypto Name',
    example: 'Bitcoin',
  })
  cryptoName: string;

  @IsString()
  @ApiProperty({
    description: 'Crypto Price',
    example: '30000',
  })
  price: string;

  @IsString()
  @ApiProperty({
    description: 'Crypto Change',
    example: '5.7',
  })
  last24h: string;

  @IsString()
  @ApiProperty({
    description: 'Crypto Volume',
    example: '100000',
  })
  vol24h: string;
}
