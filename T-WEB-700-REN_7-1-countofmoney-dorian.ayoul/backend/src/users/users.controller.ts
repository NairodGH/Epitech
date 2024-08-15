import {
  Body,
  Controller,
  Get,
  HttpCode,
  HttpStatus,
  Post,
  Patch,
  Req,
  UseGuards,
} from '@nestjs/common';
import { UsersService } from './users.service';
import { LoginDto } from './dto/login.dto';
import { AuthGuard } from '@nestjs/passport';
import {
  ApiBearerAuth,
  ApiBody,
  ApiOperation,
  ApiResponse,
  ApiTags,
} from '@nestjs/swagger';
import { UserDto } from './dto/user.dto';
import { OAuthDto } from './dto/oauth.dto';
import { UpdateUserDto } from './dto/updateuser.dto';

@Controller('users')
@ApiTags('Users')
export class UsersController {
  constructor(private readonly usersService: UsersService) {}

  @Post('register')
  @HttpCode(HttpStatus.CREATED)
  @ApiOperation({
    summary: 'Register',
    description: 'Register and returns a JWT token.',
  })
  @ApiBody({
    type: LoginDto,
    required: true,
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: UserDto,
  })
  async register(@Body() body: LoginDto) {
    return this.usersService.register(body);
  }

  @Post('login')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Login',
    description: 'Login and returns a JWT token.',
  })
  @ApiBody({
    type: LoginDto,
    required: true,
  })
  @ApiResponse({
    status: 200,
    schema: {
      type: 'object',
      properties: {
        access_token: {
          type: 'string',
        },
      },
    },
  })
  async login(@Body() body: LoginDto) {
    return this.usersService.login(body);
  }

  @Post('auth/google')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'OAuth Google',
    description: 'Connect with OAuth and returns a JWT token.',
  })
  @ApiBody({
    type: OAuthDto,
    required: true,
  })
  @ApiResponse({
    status: 200,
    schema: {
      type: 'object',
      properties: {
        access_token: {
          type: 'string',
        },
      },
    },
  })
  async authGoogle(@Body() body: OAuthDto) {
    return this.usersService.authGoogle(body);
  }

  @UseGuards(AuthGuard('jwt'))
  @Get('logout')
  @HttpCode(HttpStatus.NO_CONTENT)
  @ApiOperation({
    summary: 'Logout',
    description: 'Logout from the application.',
  })
  @ApiBearerAuth()
  @ApiResponse({
    status: HttpStatus.NO_CONTENT,
    description: 'No Content',
  })
  async logout(@Req() req: ParameterDecorator) {
    return this.usersService.logout(req);
  }

  @UseGuards(AuthGuard('jwt'))
  @Get('profile')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Profile',
    description: 'Get the profile of the current user.',
  })
  @ApiBearerAuth()
  @ApiResponse({
    status: HttpStatus.OK,
    type: UserDto,
  })
  async profile(@Req() req: ParameterDecorator) {
    return this.usersService.profile(req);
  }

  @UseGuards(AuthGuard('jwt'))
  @Patch('profile')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Update Profile',
    description: 'Update the profile of the current user.',
  })
  @ApiBearerAuth()
  @ApiBody({
    type: UpdateUserDto,
    required: true,
  })
  @ApiResponse({
    status: HttpStatus.OK,
    description: 'User updated',
  })
  async updateProfile(
    @Body() body: UpdateUserDto,
    @Req() req: ParameterDecorator,
  ) {
    return this.usersService.updateProfile(body, req);
  }
}
