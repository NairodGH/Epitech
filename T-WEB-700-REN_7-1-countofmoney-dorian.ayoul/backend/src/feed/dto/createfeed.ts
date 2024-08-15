import { ApiProperty } from '@nestjs/swagger';
import { IsString } from 'class-validator';

export class CreateFeedDto {
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
    description: 'Description',
    example:
      "Le Média N°1 sur l'actualité des crypto-monnaies : Bitcoin, Ethereum, Litecoin... Analyses, Trading, lCO, Minage et Wallets.",
  })
  description: string;
}
