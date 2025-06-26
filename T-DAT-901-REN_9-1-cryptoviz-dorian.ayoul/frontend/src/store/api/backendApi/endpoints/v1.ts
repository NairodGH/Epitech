import backendApi from "../backendApi";
const injectedRtkApi = backendApi.injectEndpoints({
  endpoints: (build) => ({
    cryptosControllerGetCryptos: build.query<CryptosControllerGetCryptosApiResponse, CryptosControllerGetCryptosApiArg>(
      {
        query: () => ({ url: `/cryptos/all` }),
      }
    ),
    cryptosControllerGetTopCryptos: build.query<
      CryptosControllerGetTopCryptosApiResponse,
      CryptosControllerGetTopCryptosApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos/best`,
        params: {
          top: queryArg.top,
        },
      }),
    }),
    cryptosControllerGetCryptoById: build.query<
      CryptosControllerGetCryptoByIdApiResponse,
      CryptosControllerGetCryptoByIdApiArg
    >({
      query: (queryArg) => ({ url: `/cryptos/${queryArg.cmid}` }),
    }),
    cryptosControllerGetCryptoHistory: build.query<
      CryptosControllerGetCryptoHistoryApiResponse,
      CryptosControllerGetCryptoHistoryApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos/${queryArg.cmid}/history/${queryArg.period}`,
      }),
    }),
    cryptosControllerGetCryptoCandlestick: build.query<
      CryptosControllerGetCryptoCandlestickApiResponse,
      CryptosControllerGetCryptoCandlestickApiArg
    >({
      query: (queryArg) => ({ url: `/cryptos/candlestick/${queryArg.cmid}` }),
    }),
    feedsControllerGetFeedsProviders: build.query<
      FeedsControllerGetFeedsProvidersApiResponse,
      FeedsControllerGetFeedsProvidersApiArg
    >({
      query: () => ({ url: `/feeds/providers` }),
    }),
    feedsControllerGetNFeedsWithOffset: build.query<
      FeedsControllerGetNFeedsWithOffsetApiResponse,
      FeedsControllerGetNFeedsWithOffsetApiArg
    >({
      query: (queryArg) => ({
        url: `/feeds`,
        params: {
          n: queryArg.n,
          offset: queryArg.offset,
          feedId: queryArg.feedId,
        },
      }),
    }),
    feedsControllerGetFeedsCount: build.query<
      FeedsControllerGetFeedsCountApiResponse,
      FeedsControllerGetFeedsCountApiArg
    >({
      query: () => ({ url: `/feeds/count` }),
    }),
    feedsControllerGetFeedsByPeriod: build.query<
      FeedsControllerGetFeedsByPeriodApiResponse,
      FeedsControllerGetFeedsByPeriodApiArg
    >({
      query: (queryArg) => ({
        url: `/feeds/period`,
        params: {
          startDate: queryArg.startDate,
          endDate: queryArg.endDate,
          feedId: queryArg.feedId,
        },
      }),
    }),
    feedsControllerGetDashboardFeeds: build.query<
      FeedsControllerGetDashboardFeedsApiResponse,
      FeedsControllerGetDashboardFeedsApiArg
    >({
      query: () => ({ url: `/feeds/dashboard` }),
    }),
    feedsControllerGetById: build.query<FeedsControllerGetByIdApiResponse, FeedsControllerGetByIdApiArg>({
      query: (queryArg) => ({ url: `/feeds/${queryArg.id}` }),
    }),
    scrapperControllerGetCryptos: build.query<
      ScrapperControllerGetCryptosApiResponse,
      ScrapperControllerGetCryptosApiArg
    >({
      query: () => ({ url: `/scrapper` }),
    }),
  }),
  overrideExisting: false,
});
export { injectedRtkApi as v1 };
export type CryptosControllerGetCryptosApiResponse = /** status 200  */ CryptoSummaryDto[];
export type CryptosControllerGetCryptosApiArg = void;
export type CryptosControllerGetTopCryptosApiResponse = /** status 200  */ TopCryptoDto[];
export type CryptosControllerGetTopCryptosApiArg = {
  /** Top X cryptos. */
  top: number;
};
export type CryptosControllerGetCryptoByIdApiResponse = /** status 200  */ CryptoDetailsDto;
export type CryptosControllerGetCryptoByIdApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
};
export type CryptosControllerGetCryptoHistoryApiResponse = /** status 200  */ CryptoDataDto;
export type CryptosControllerGetCryptoHistoryApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
  /** Period of the crypto. */
  period: string;
};
export type CryptosControllerGetCryptoCandlestickApiResponse = /** status 200  */ CryptoCandlestickDto[];
export type CryptosControllerGetCryptoCandlestickApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
};
export type FeedsControllerGetFeedsProvidersApiResponse = /** status 200  */ FeedProviderDto[];
export type FeedsControllerGetFeedsProvidersApiArg = void;
export type FeedsControllerGetNFeedsWithOffsetApiResponse = /** status 200  */ FeedItemSummaryDto[];
export type FeedsControllerGetNFeedsWithOffsetApiArg = {
  n: number;
  offset: number;
  feedId?: string;
};
export type FeedsControllerGetFeedsCountApiResponse = /** status 200  */ number;
export type FeedsControllerGetFeedsCountApiArg = void;
export type FeedsControllerGetFeedsByPeriodApiResponse = /** status 200  */ FeedItemSummaryDto[];
export type FeedsControllerGetFeedsByPeriodApiArg = {
  startDate: string;
  endDate: string;
  feedId?: string;
};
export type FeedsControllerGetDashboardFeedsApiResponse = /** status 200  */ FeedItemSummaryDto[];
export type FeedsControllerGetDashboardFeedsApiArg = void;
export type FeedsControllerGetByIdApiResponse = /** status 200  */ FeedItemDetailsDto;
export type FeedsControllerGetByIdApiArg = {
  id: string;
};
export type ScrapperControllerGetCryptosApiResponse = /** status 200  */ ScrapperDto[];
export type ScrapperControllerGetCryptosApiArg = void;
export type CryptoSummaryDto = {
  /** Id */
  id: string;
  /** Name */
  name: string;
  /** Symbol */
  symbol: string;
  /** URL to the crypto image */
  imageUrl: string;
  /** Description */
  description: string;
};
export type TopCryptoValue = {
  /** Value */
  value: number;
  /** Date */
  createdAt: string;
};
export type TopCryptoDto = {
  /** Id */
  id: string;
  /** Name */
  name: string;
  /** Symbol */
  symbol: string;
  /** URL to the crypto image */
  imageUrl: string;
  /** Description */
  description: string;
  /** Top crypto values */
  price: TopCryptoValue[];
};
export type CryptoDetailsDto = {
  /** Id */
  id: string;
  /** Name */
  name: string;
  /** Symbol */
  symbol: string;
  /** URL to the crypto image */
  imageUrl: string;
  /** Description */
  description: string;
  /** Current price */
  currentPrice: number;
  /** Lowest price of the batch */
  lowestPriceBatch: number;
  /** Highest price of the batch */
  highestPriceBatch: number;
  /** Id from Coinmarketcap */
  coinmarketId: number;
};
export type CryptoDataDto = {
  /** Id */
  id: string;
  /** Current price */
  currentPrice: number;
  /** Lowest price of the day */
  lowestPriceBatch: number;
  /** Highest price of the day */
  highestPriceBatch: number;
  /** Price history depending on the period */
  priceHistory: number[];
};
export type CandlestickValueDto = {
  /** Id */
  id: string;
  /** Opening price */
  openingPrice: number;
  /** Closing price */
  closingPrice: number;
  /** High price */
  highPrice: number;
  /** Low price */
  lowPrice: number;
  /** Date */
  date: string;
};
export type CryptoCandlestickDto = {
  /** Id */
  id: string;
  /** Candlestick values */
  candlestickValues: CandlestickValueDto[];
};
export type FeedProviderDto = {
  /** Provider ID */
  id: string;
  /** Name */
  name: string;
  /** URL */
  link: string;
  /** Provider date */
  createdAt: string;
  /** Provider date */
  updatedAt: string;
};
export type FeedItemSummaryDto = {
  /** Article ID */
  id: string;
  /** Article Title */
  title: string;
  /** Image URL */
  imageUrl: string;
  /** Article date */
  pubDate: string;
  /** Article date */
  createdAt: string;
  /** Feed ID */
  feedId: string;
};
export type FeedItemDetailsDto = {
  /** Article ID */
  id: string;
  /** Article Title */
  title: string;
  /** Image URL */
  imageUrl: string;
  /** Article date */
  pubDate: string;
  /** Article date */
  createdAt: string;
  /** Feed ID */
  feedId: string;
  /** Article body */
  content: string;
  /** Article source */
  link: string;
};
export type ScrapperDto = {
  /** Crypto Name */
  cryptoName: string;
  /** Crypto Price */
  price: string;
  /** Crypto Change */
  last24h: string;
  /** Crypto Volume */
  vol24h: string;
};
export const {
  useCryptosControllerGetCryptosQuery,
  useLazyCryptosControllerGetCryptosQuery,
  useCryptosControllerGetTopCryptosQuery,
  useLazyCryptosControllerGetTopCryptosQuery,
  useCryptosControllerGetCryptoByIdQuery,
  useLazyCryptosControllerGetCryptoByIdQuery,
  useCryptosControllerGetCryptoHistoryQuery,
  useLazyCryptosControllerGetCryptoHistoryQuery,
  useCryptosControllerGetCryptoCandlestickQuery,
  useLazyCryptosControllerGetCryptoCandlestickQuery,
  useFeedsControllerGetFeedsProvidersQuery,
  useLazyFeedsControllerGetFeedsProvidersQuery,
  useFeedsControllerGetNFeedsWithOffsetQuery,
  useLazyFeedsControllerGetNFeedsWithOffsetQuery,
  useFeedsControllerGetFeedsCountQuery,
  useLazyFeedsControllerGetFeedsCountQuery,
  useFeedsControllerGetFeedsByPeriodQuery,
  useLazyFeedsControllerGetFeedsByPeriodQuery,
  useFeedsControllerGetDashboardFeedsQuery,
  useLazyFeedsControllerGetDashboardFeedsQuery,
  useFeedsControllerGetByIdQuery,
  useLazyFeedsControllerGetByIdQuery,
  useScrapperControllerGetCryptosQuery,
  useLazyScrapperControllerGetCryptosQuery,
} = injectedRtkApi;
