import { Test, TestingModule } from '@nestjs/testing';
import { CryptosGateway } from './cryptos.gateway';

describe('CryptosGateway', () => {
  let gateway: CryptosGateway;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [CryptosGateway],
    }).compile();

    gateway = module.get<CryptosGateway>(CryptosGateway);
  });

  it('should be defined', () => {
    expect(gateway).toBeDefined();
  });
});
