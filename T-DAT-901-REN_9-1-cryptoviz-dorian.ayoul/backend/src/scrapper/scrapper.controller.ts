import { Controller, Get, HttpCode, HttpStatus } from '@nestjs/common';
import { ScrapperService } from './scrapper.service';
import { ApiOperation, ApiResponse, ApiTags } from '@nestjs/swagger';
import { ScrapperDto } from './dto/scrapper.dto';

@Controller('/scrapper')
@ApiTags('Scrapper')
export class ScrapperController {
  constructor(private readonly scrapperService: ScrapperService) {}

  @Get()
  @HttpCode(HttpStatus.OK)
  @ApiOperation({ summary: 'Get Cryptos' })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [ScrapperDto],
  })
  async getCryptos() {
    return await this.scrapperService.scrapeCoinMarketCap();
  }
}
