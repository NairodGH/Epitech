import { Test, TestingModule } from '@nestjs/testing';
import { CoinMarketService } from './coinmarket.service';

describe('CoinMarketService', () => {
  let service: CoinMarketService;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [CoinMarketService],
    }).compile();

    service = module.get<CoinMarketService>(CoinMarketService);
  });

  it('should be defined', () => {
    expect(service).toBeDefined();
  });
});
