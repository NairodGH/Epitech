import { ApiProperty } from '@nestjs/swagger';
import { IsArray, IsString, IsUUID } from 'class-validator';

export class UpdateUserDto {
  @IsArray()
  @IsUUID('all', { each: true })
  @ApiProperty({
    description: 'Cryptos',
    example: [
      '942644ff-154f-44b1-921d-a917e572d4c5',
      'dadc9fbe-40eb-4878-ac60-03360bcec474',
    ],
  })
  cryptos?: string[];

  @IsArray()
  @IsString({ each: true })
  @ApiProperty({
    description: 'Keywords',
    example: ['Bitcoin', 'Ethereum', 'Crash'],
  })
  keywords?: string[];
}
