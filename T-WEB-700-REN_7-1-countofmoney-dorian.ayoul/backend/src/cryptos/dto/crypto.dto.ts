import { ApiProperty } from '@nestjs/swagger';
import { IsBoolean, IsString, IsUUID } from 'class-validator';

export class CryptoDto {
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

  @IsBoolean()
  @ApiProperty({
    description: 'Default',
    example: true,
  })
  default: boolean;
}
