import { ApiProperty } from '@nestjs/swagger';
import { IsString } from 'class-validator';

export class FeedProviderDto {
  @IsString()
  @ApiProperty({
    description: 'Provider ID',
    example: '1b9d6bcd-bbfd-4b2d-9b5d-ab8dfbbd4bed',
  })
  id: string;

  @IsString()
  @ApiProperty({
    description: 'Name',
    example: 'CoinJournal',
  })
  name: string;

  @IsString()
  @ApiProperty({
    description: 'URL',
    example: 'https://coinjournal.net/fr/actualites/feed/',
  })
  link: string;

  @IsString()
  @ApiProperty({
    description: 'Provider date',
    example: '2021-07-20T09:00:00.000Z',
  })
  createdAt: string;

  @IsString()
  @ApiProperty({
    description: 'Provider date',
    example: '2021-07-20T09:00:00.000Z',
  })
  updatedAt: string;
}
