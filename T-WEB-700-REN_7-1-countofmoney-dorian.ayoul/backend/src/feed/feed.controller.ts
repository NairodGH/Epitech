import {
  Body,
  Controller,
  Get,
  HttpCode,
  HttpStatus,
  Param,
  Post,
  Req,
  SetMetadata,
  UseGuards,
} from '@nestjs/common';
import { FeedService } from './feed.service';
import {
  ApiBearerAuth,
  ApiBody,
  ApiOperation,
  ApiResponse,
  ApiTags,
} from '@nestjs/swagger';
import { RolesGuard } from 'src/users/roles.guard';
import { AuthGuard } from '@nestjs/passport';
import { CreateFeedDto } from './dto/createfeed';
import { GetFeedItemsDto } from './dto/getfeeditems';
import { GetFeedItemDto } from './dto/getfeeditem';
import { OptionalJwtAuthGuard } from 'src/jwt/OptionnalJwtAuthGuard';

@Controller('articles')
@ApiTags('Feeds')
export class FeedController {
  constructor(private readonly feedService: FeedService) {}

  @UseGuards(AuthGuard('jwt'), RolesGuard)
  @Post()
  @HttpCode(HttpStatus.CREATED)
  @ApiOperation({
    summary: 'Add feed item',
    description: 'Add feed item',
  })
  @ApiBearerAuth()
  @SetMetadata('role', 'ADMIN')
  @ApiBody({
    type: CreateFeedDto,
    required: true,
  })
  @ApiResponse({
    status: HttpStatus.CREATED,
    type: CreateFeedDto,
  })
  async addFeed(@Body() feed: CreateFeedDto) {
    return this.feedService.addFeed(feed);
  }

  @Get()
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get all feed items',
    description: 'Get all feed items',
  })
  @ApiResponse({
    status: HttpStatus.OK,
  })
  async getAll() {
    return this.feedService.getAll();
  }

  @UseGuards(OptionalJwtAuthGuard)
  @Get('items')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get the K items',
    description: 'Get the K items',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [GetFeedItemsDto],
  })
  async getItems(@Req() req: ParameterDecorator) {
    return this.feedService.getItems(req);
  }

  @Get('items/:id')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get the item by id',
    description: 'Get the item by id',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: GetFeedItemDto,
  })
  async getItemById(@Param('id') id: string) {
    return this.feedService.getItemById(id);
  }

  @Get(':id')
  @HttpCode(HttpStatus.OK)
  @ApiOperation({
    summary: 'Get feed item by id',
    description: 'Get feed item by id',
  })
  @ApiResponse({
    status: HttpStatus.OK,
  })
  async getById(@Param('id') id: string) {
    return this.feedService.getById(id);
  }
}
