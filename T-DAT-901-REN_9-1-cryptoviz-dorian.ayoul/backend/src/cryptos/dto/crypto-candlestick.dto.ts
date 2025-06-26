import { ApiProperty } from '@nestjs/swagger';
import { IsArray, IsNumber, IsUUID } from 'class-validator';

export class CandlestickValueDto {
  @IsUUID()
  @ApiProperty({
    description: 'Id',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  id: string;

  @IsNumber()
  @ApiProperty({
    description: 'Opening price',
    example: 10000,
  })
  openingPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'Closing price',
    example: 10000,
  })
  closingPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'High price',
    example: 10000,
  })
  highPrice: number;

  @IsNumber()
  @ApiProperty({
    description: 'Low price',
    example: 10000,
  })
  lowPrice: number;

  @ApiProperty({
    description: 'Date',
    example: '2021-01-01',
  })
  date: Date;
}

export class CryptoCandlestickDto {
  @IsUUID()
  @ApiProperty({
    description: 'Id',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  id: string;

  @IsArray()
  @ApiProperty({
    description: 'Candlestick values',
    example: [
      {
        id: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
        openingPrice: 10000,
        closingPrice: 10000,
        highPrice: 10000,
        lowPrice: 10000,
        date: '2021-01-01',
      },
    ],
    type: [CandlestickValueDto],
  })
  candlestickValues: CandlestickValueDto[];
}
