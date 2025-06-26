import { Controller, Get, HttpStatus, Param, Query } from '@nestjs/common';
import { FeedsService } from './feeds.service';
import { ApiOperation, ApiQuery, ApiResponse, ApiTags } from '@nestjs/swagger';
import { FeedItemDetailsDto, FeedItemSummaryDto } from './dto/feed-item.dto';
import { FeedProviderDto } from './dto/feed-provider.dto';

@Controller('feeds')
@ApiTags('Feeds')
export class FeedsController {
  constructor(private readonly feedsService: FeedsService) {}

  @Get('providers')
  @ApiOperation({ summary: 'Get feeds providers' })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [FeedProviderDto],
  })
  async getFeedsProviders() {
    return this.feedsService.getFeedsProviders();
  }

  @Get()
  @ApiOperation({ summary: 'Get N feeds with offset' })
  @ApiQuery({ name: 'n', type: Number, required: true })
  @ApiQuery({ name: 'offset', type: Number, required: true })
  @ApiQuery({ name: 'feedId', type: String, required: false })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [FeedItemSummaryDto],
  })
  async getNFeedsWithOffset(
    @Query('n') n: number,
    @Query('offset') offset: number,

    @Query('feedId') feedId?: string,
  ) {
    if (feedId) {
      return this.feedsService.getNFeedsWithOffsetByFeedId(n, offset, feedId);
    }

    return this.feedsService.getNFeedsWithOffset(n, offset);
  }

  @Get('count')
  @ApiOperation({ summary: 'Get number of feeds' })
  @ApiResponse({
    status: HttpStatus.OK,
    type: Number,
  })
  async getFeedsCount() {
    return this.feedsService.getFeedsCount();
  }

  @Get('period')
  @ApiOperation({ summary: 'Get N feeds with offset' })
  @ApiQuery({ name: 'startDate', type: Date, required: true })
  @ApiQuery({ name: 'endDate', type: Date, required: true })
  @ApiQuery({ name: 'feedId', type: String, required: false })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [FeedItemSummaryDto],
  })
  async getFeedsByPeriod(
    @Query('startDate') startDate: Date,
    @Query('endDate') endDate: Date,

    @Query('feedId') feedId?: string,
  ) {
    if (feedId) {
      return this.feedsService.getFeedsByPeriodAndFeedId(
        startDate,
        endDate,
        feedId,
      );
    }

    return this.feedsService.getFeedsByPeriod(startDate, endDate);
  }

  @Get('dashboard')
  @ApiOperation({ summary: 'Get feeds for dashboard' })
  @ApiResponse({
    status: HttpStatus.OK,
    type: [FeedItemSummaryDto],
  })
  async getDashboardFeeds() {
    return this.feedsService.getDashboardFeeds();
  }

  @Get(':id')
  @ApiOperation({
    summary: 'Get feed item by id',
    description: 'Get feed item by id',
  })
  @ApiResponse({
    status: HttpStatus.OK,
    type: FeedItemDetailsDto,
  })
  async getById(@Param('id') id: string) {
    return this.feedsService.getById(id);
  }
}
