import {
  Controller,
  Get,
  HttpCode,
  HttpStatus,
  Param,
  Query,
} from '@nestjs/common';
import { CryptosService } from './cryptos.service';
import {
  ApiOperation,
  ApiParam,
  ApiQuery,
  ApiResponse,
  ApiTags,
} from '@nestjs/swagger';
import { CryptoDataDto } from './dto/crypto-data.dto';
import { Period } from '@prisma/client';
import {
  CryptoDetailsDto,
  CryptoSummaryDto,
  TopCryptoDto,
} from './dto/crypto.dto';
import { CryptoCandlestickDto } from './dto/crypto-candlestick.dto';

@Controller('cryptos')
@ApiTags('Cryptos')
export class CryptosController {
  constructor(private readonly cryptosService: CryptosService) {}

  @Get('/all')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Cryptos',
    description: 'Get Cryptos.',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [CryptoSummaryDto],
  })
  async getCryptos() {
    return this.cryptosService.getCryptos();
  }

  @Get('/best')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Top X Cryptos',
    description: 'Get Top X Cryptos.',
  })
  @ApiQuery({
    name: 'top',
    required: true,
    description: 'Top X cryptos.',
    example: '5',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [TopCryptoDto],
  })
  async getTopCryptos(@Query('top') top?: number) {
    return this.cryptosService.getTopCryptos(top, 'DAY');
  }

  @Get(':cmid')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Crypto By Id',
    description: 'Get Crypto details by cmid.',
  })
  @ApiParam({
    name: 'cmid',
    required: true,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: CryptoDetailsDto,
  })
  async getCryptoById(@Param('cmid') cmid: string) {
    return this.cryptosService.getCryptoById(cmid);
  }

  @Get(':cmid/history/:period')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Crypto History',
    description: 'Get Crypto history by cmid and period.',
  })
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

  @Get('/candlestick/:cmid')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get Crypto Candlestick',
    description: 'Get Crypto candlestick by cmid.',
  })
  @ApiParam({
    name: 'cmid',
    required: true,
    description: 'Cmid of the crypto.',
    example: '0440ff61-4a92-44a4-89e7-f23ecbc4002f',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [CryptoCandlestickDto],
  })
  async getCryptoCandlestick(@Param('cmid') cmid: string) {
    return this.cryptosService.getCryptoCandlestick(cmid);
  }
}
