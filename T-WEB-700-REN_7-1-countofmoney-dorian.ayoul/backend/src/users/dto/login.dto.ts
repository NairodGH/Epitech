import { ApiProperty } from '@nestjs/swagger';
import { IsString } from 'class-validator';

export class LoginDto {
  @IsString()
  @ApiProperty({
    description: 'Email',
    example: 'test.user@mail.com',
  })
  email: string;

  @IsString()
  @ApiProperty({
    description: 'Password',
    example: 'secretP4$$123',
  })
  password: string;
}
