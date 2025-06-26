import {
  ConnectedSocket,
  MessageBody,
  SubscribeMessage,
  WebSocketGateway,
  WebSocketServer,
} from '@nestjs/websockets';
import { Server, Socket } from 'socket.io';
import { CryptosService } from './cryptos.service';
import { Logger } from '@nestjs/common';

@WebSocketGateway({
  cors: {
    origin: '*',
  },
})
export class CryptosGateway {
  private readonly logger = new Logger(CryptosGateway.name);

  constructor(private readonly cryptosService: CryptosService) {}

  @WebSocketServer()
  server: Server;

  async emitCandlestickJobDone() {
    this.server.emit('candlestickJobDone');
  }

  @SubscribeMessage('candlestick')
  async handleCandlestick(
    @MessageBody() body: { cmid: string },
    @ConnectedSocket() client: Socket,
  ) {
    const cmid = body.cmid;

    try {
      this.logger.log(`Received candlestick request for ${cmid}`);
      const data = await this.cryptosService.getCryptoCandlestick(cmid);

      client.emit('candlestick', data);
    } catch (error) {
      this.logger.error(
        `Error processing candlestick request: ${error.message}`,
      );
    }
  }

  async emitCoinmarketJobDone() {
    this.server.emit('coinmarketJobDone');
  }

  @SubscribeMessage('cryptos')
  async handleCryptos(@ConnectedSocket() client: Socket) {
    try {
      this.logger.log(`Received cryptos request`);
      const data = await this.cryptosService.getCryptos();

      client.emit('cryptos', data);
    } catch (error) {
      this.logger.error(`Error processing cryptos request: ${error.message}`);
    }
  }

  @SubscribeMessage('bestCryptos')
  async handleBestCryptos(
    @MessageBody() body: { top: number; period: 'YEAR' | 'MONTH' | 'DAY' },
    @ConnectedSocket() client: Socket,
  ) {
    try {
      this.logger.log(`Received best cryptos request`);
      const data = await this.cryptosService.getTopCryptos(
        body.top,
        body.period,
      );

      client.emit('bestCryptos', data);
    } catch (error) {
      this.logger.error(
        `Error processing best cryptos request: ${error.message}`,
      );
    }
  }
}
