import {
  Controller,
  HttpCode,
  HttpStatus,
  Post,
  Query,
  SetMetadata,
  UseGuards,
} from '@nestjs/common';
import {
  ApiBearerAuth,
  ApiOperation,
  ApiResponse,
  ApiTags,
} from '@nestjs/swagger';
import { ConstantService } from './constant.service';
import { AuthGuard } from '@nestjs/passport';
import { RolesGuard } from 'src/users/roles.guard';

@Controller('constant')
@ApiTags('Constants')
export class ConstantController {
  constructor(private readonly constantService: ConstantService) {}

  @UseGuards(AuthGuard('jwt'), RolesGuard)
  @Post('articles-number')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Update or create number of articles',
    description: 'Update or create number of articles',
  })
  @ApiBearerAuth()
  @SetMetadata('role', 'ADMIN')
  @ApiResponse({
    status: HttpStatus.OK,
    type: Number,
  })
  async updateArticlesNumber(@Query('number') number?: number) {
    return this.constantService.updateArticlesNumber(number);
  }
}
