import {
  Body,
  Controller,
  Delete,
  Get,
  HttpCode,
  HttpStatus,
  Param,
  Post,
  Query,
  Req,
  SetMetadata,
  UseGuards,
} from '@nestjs/common';
import { CryptosService } from './cryptos.service';
import { AuthGuard } from '@nestjs/passport';
import {
  ApiBearerAuth,
  ApiBody,
  ApiOperation,
  ApiParam,
  ApiQuery,
  ApiResponse,
  ApiTags,
} from '@nestjs/swagger';
import { CryptoDetailDto } from './dto/cryptodetail.dto';
import { CryptoDataDto } from './dto/cryptodata.dto';
import { Period } from '@prisma/client';
import { UpdateCryptoDto } from './dto/updatecrypto.dto';
import { CryptoDto } from './dto/crypto.dto';
import { RolesGuard } from 'src/users/roles.guard';
import { DefaultCryptoDto } from './dto/defaultcrypto.dto';

@Controller('cryptos')
@ApiTags('Cryptos')
export class CryptosController {
  constructor(private readonly cryptosService: CryptosService) {}

  @Get('/all')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Available Cryptos',
    description: 'Get Available Cryptos.',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [CryptoDto],
  })
  async getAvailableCryptos(@Req() req: ParameterDecorator) {
    return this.cryptosService.getAvailableCryptos(req);
  }

  @Get('/dashboard')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Corresponding Cryptos',
    description: 'Get Corresponding Cryptos.',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [CryptoDto],
  })
  async getDashboardCryptos(@Req() req: ParameterDecorator) {
    return this.cryptosService.getDashboardCryptos(req);
  }

  @Get()
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Cryptos',
    description: 'Get Cryptos details by cmids.',
  })
  @ApiQuery({
    name: 'cmids',
    required: false,
    description: 'Comma separated list of cmids.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [CryptoDetailDto],
  })
  async getCryptos(@Query('cmids') cmids?: string) {
    return this.cryptosService.getCryptos(cmids);
  }

  @UseGuards(AuthGuard('jwt'))
  @Get(':cmid')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Crypto By Id',
    description: 'Get Crypto details by cmid.',
  })
  @ApiBearerAuth()
  @ApiParam({
    name: 'cmid',
    required: true,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: CryptoDetailDto,
  })
  async getCryptoById(@Param('cmid') cmid: string) {
    return this.cryptosService.getCryptoById(cmid);
  }

  //   TODO not sure
  //   @UseGuards(AuthGuard('jwt'))
  @Get(':cmid/history/:period')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Crypto History',
    description: 'Get Crypto history by cmid and period.',
  })
  //   @ApiBearerAuth()
  @ApiParam({
    name: 'cmid',
    required: true,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiParam({
    name: 'period',
    required: true,
    description: 'Period of the crypto.',
    example: 'DAY',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: CryptoDataDto,
  })
  async getCryptoHistory(
    @Param('cmid') cmid: string,
    @Param('period') period: Period,
  ) {
    return this.cryptosService.getCryptoHistory(cmid, period);
  }

  @UseGuards(AuthGuard('jwt'), RolesGuard)
  @Post()
  @HttpCode(HttpStatus.CREATED)
  @ApiOperation({
    summary: 'Add Crypto',
    description: 'Add Crypto.',
  })
  @ApiBearerAuth()
  @SetMetadata('role', 'ADMIN')
  @ApiBody({
    type: UpdateCryptoDto,
    required: true,
  })
  @ApiQuery({
    name: 'cmid',
    required: false,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.CREATED,
    type: UpdateCryptoDto,
  })
  async updateCrypto(
    @Body() cryptoData: UpdateCryptoDto,
    @Query('cmid') cmid?: string,
  ) {
    return this.cryptosService.updateCrypto(cryptoData, cmid);
  }

  @UseGuards(AuthGuard('jwt'), RolesGuard)
  @Delete(':cmid')
  @HttpCode(HttpStatus.NO_CONTENT)
  @ApiOperation({
    summary: 'Delete Crypto',
    description: 'Delete Crypto by cmid.',
  })
  @ApiBearerAuth()
  @SetMetadata('role', 'ADMIN')
  @ApiParam({
    name: 'cmid',
    required: true,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.NO_CONTENT,
  })
  async deleteCrypto(@Param('cmid') cmid: string) {
    return this.cryptosService.deleteCrypto(cmid);
  }

  @UseGuards(AuthGuard('jwt'), RolesGuard)
  @Post('/defaults')
  @ApiOperation({
    summary: 'Set Default Crypto',
    description: 'Set Default Crypto.',
  })
  @ApiBearerAuth()
  @SetMetadata('role', 'ADMIN')
  @ApiBody({
    type: DefaultCryptoDto,
    required: true,
  })
  @ApiResponse({
    type: DefaultCryptoDto,
  })
  async defaultCrypto(@Body() cryptoData: DefaultCryptoDto) {
    return this.cryptosService.defaultCryptos(cryptoData);
  }
}
