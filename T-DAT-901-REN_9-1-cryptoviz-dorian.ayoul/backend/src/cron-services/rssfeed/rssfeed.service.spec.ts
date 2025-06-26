import { Test, TestingModule } from '@nestjs/testing';
import { RSSfeedService } from './rssfeed.service';

describe('RSSfeedService', () => {
  let service: RSSfeedService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [RSSfeedService],
    }).compile();

    service = module.get<RSSfeedService>(RSSfeedService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
