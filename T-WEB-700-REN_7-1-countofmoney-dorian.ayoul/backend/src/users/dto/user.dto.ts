import { ApiProperty } from '@nestjs/swagger';
import { IsArray, IsEnum, IsString, IsUUID } from 'class-validator';

export class UserDto {
  @IsString()
  @ApiProperty({
    description: 'Email',
    example: 'test.user@mail.com',
  })
  email: string;

  @IsEnum(['ADMIN', 'USER'])
  @ApiProperty({
    description: 'Role',
    example: 'USER',
  })
  role: string;

  @IsArray()
  @IsUUID('all', { each: true })
  @ApiProperty({
    description: 'Cryptos',
    example: [
      '942644ff-154f-44b1-921d-a917e572d4c5',
      'dadc9fbe-40eb-4878-ac60-03360bcec474',
    ],
  })
  cryptos: string[];
}
