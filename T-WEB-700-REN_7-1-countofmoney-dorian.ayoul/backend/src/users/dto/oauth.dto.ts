import { ApiProperty } from '@nestjs/swagger';
import { IsString } from 'class-validator';

export class OAuthDto {
  @IsString()
  @ApiProperty({
    description: 'Token',
    example: '1010101',
  })
  token: string;

  @IsString()
  @ApiProperty({
    description: 'API',
    example: 'google',
  })
  api: string;
}
