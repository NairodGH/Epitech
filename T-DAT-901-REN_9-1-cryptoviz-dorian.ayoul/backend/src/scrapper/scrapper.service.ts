import { Injectable } from '@nestjs/common';
import puppeteer from 'puppeteer';

@Injectable()
export class ScrapperService {
  async scrapeCoinMarketCap() {
    const url = 'https://www.coingecko.com/fr';
    const browser = await puppeteer.launch({ headless: true });
    const page = await browser.newPage();

    try {
      await page.goto(url, { waitUntil: 'domcontentloaded' });

      const crypto = await page.evaluate(() => {
        const rows = Array.from(document.querySelectorAll('table tbody tr'));
        return rows.slice(0, 100).map((row) => {
          let cryptoName =
            row
              .querySelector('td:nth-child(3) a div div:nth-child(1)')
              ?.textContent?.trim() || '';
          cryptoName = cryptoName.split('\n')[0].trim();
          const price =
            row.querySelector('td:nth-child(5) span')?.textContent?.trim() ||
            '';
          // Pas de valeur explicite negative, verification par l'icon.
          const last24hElement = row.querySelector('td:nth-child(7)');
          const last24hValue =
            last24hElement?.querySelector('span')?.textContent?.trim() || '';
          const isNegative =
            last24hElement?.querySelector('i.fa-caret-down') !== null;
          const last24h = isNegative ? `-${last24hValue}` : last24hValue;

          const vol24h =
            row.querySelector('td:nth-child(10) span')?.textContent?.trim() ||
            '';

          return { cryptoName, price, last24h, vol24h };
        });
      });
      return crypto;
    } catch (error) {
      console.error('error scraping CoinMarketCap', error);
      throw new Error('Failed to scrap CoinMarketCap');
    } finally {
      await browser.close();
    }
  }
}
