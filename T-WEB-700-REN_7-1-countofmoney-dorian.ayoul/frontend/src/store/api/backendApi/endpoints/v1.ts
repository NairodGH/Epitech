import backendApi from "../backendApi";
const injectedRtkApi = backendApi.injectEndpoints({
  endpoints: (build) => ({
    usersControllerRegister: build.mutation<
      UsersControllerRegisterApiResponse,
      UsersControllerRegisterApiArg
    >({
      query: (queryArg) => ({
        url: `/users/register`,
        method: "POST",
        body: queryArg.loginDto,
      }),
    }),
    usersControllerLogin: build.mutation<
      UsersControllerLoginApiResponse,
      UsersControllerLoginApiArg
    >({
      query: (queryArg) => ({
        url: `/users/login`,
        method: "POST",
        body: queryArg.loginDto,
      }),
    }),
    usersControllerAuthGoogle: build.mutation<
      UsersControllerAuthGoogleApiResponse,
      UsersControllerAuthGoogleApiArg
    >({
      query: (queryArg) => ({
        url: `/users/auth/google`,
        method: "POST",
        body: queryArg.oAuthDto,
      }),
    }),
    usersControllerLogout: build.query<
      UsersControllerLogoutApiResponse,
      UsersControllerLogoutApiArg
    >({
      query: () => ({ url: `/users/logout` }),
    }),
    usersControllerProfile: build.query<
      UsersControllerProfileApiResponse,
      UsersControllerProfileApiArg
    >({
      query: () => ({ url: `/users/profile` }),
    }),
    usersControllerUpdateProfile: build.mutation<
      UsersControllerUpdateProfileApiResponse,
      UsersControllerUpdateProfileApiArg
    >({
      query: (queryArg) => ({
        url: `/users/profile`,
        method: "PATCH",
        body: queryArg.updateUserDto,
      }),
    }),
    cryptosControllerGetAvailableCryptos: build.query<
      CryptosControllerGetAvailableCryptosApiResponse,
      CryptosControllerGetAvailableCryptosApiArg
    >({
      query: () => ({ url: `/cryptos/all` }),
    }),
    cryptosControllerGetDashboardCryptos: build.query<
      CryptosControllerGetDashboardCryptosApiResponse,
      CryptosControllerGetDashboardCryptosApiArg
    >({
      query: () => ({ url: `/cryptos/dashboard` }),
    }),
    cryptosControllerGetCryptos: build.query<
      CryptosControllerGetCryptosApiResponse,
      CryptosControllerGetCryptosApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos`,
        params: { cmids: queryArg.cmids },
      }),
    }),
    cryptosControllerUpdateCrypto: build.mutation<
      CryptosControllerUpdateCryptoApiResponse,
      CryptosControllerUpdateCryptoApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos`,
        method: "POST",
        body: queryArg.updateCryptoDto,
        params: { cmid: queryArg.cmid },
      }),
    }),
    cryptosControllerGetCryptoById: build.query<
      CryptosControllerGetCryptoByIdApiResponse,
      CryptosControllerGetCryptoByIdApiArg
    >({
      query: (queryArg) => ({ url: `/cryptos/${queryArg.cmid}` }),
    }),
    cryptosControllerDeleteCrypto: build.mutation<
      CryptosControllerDeleteCryptoApiResponse,
      CryptosControllerDeleteCryptoApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos/${queryArg.cmid}`,
        method: "DELETE",
      }),
    }),
    cryptosControllerGetCryptoHistory: build.query<
      CryptosControllerGetCryptoHistoryApiResponse,
      CryptosControllerGetCryptoHistoryApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos/${queryArg.cmid}/history/${queryArg.period}`,
      }),
    }),
    cryptosControllerDefaultCrypto: build.mutation<
      CryptosControllerDefaultCryptoApiResponse,
      CryptosControllerDefaultCryptoApiArg
    >({
      query: (queryArg) => ({
        url: `/cryptos/defaults`,
        method: "POST",
        body: queryArg.defaultCryptoDto,
      }),
    }),
    feedControllerAddFeed: build.mutation<
      FeedControllerAddFeedApiResponse,
      FeedControllerAddFeedApiArg
    >({
      query: (queryArg) => ({
        url: `/articles`,
        method: "POST",
        body: queryArg.createFeedDto,
      }),
    }),
    feedControllerGetAll: build.query<
      FeedControllerGetAllApiResponse,
      FeedControllerGetAllApiArg
    >({
      query: () => ({ url: `/articles` }),
    }),
    feedControllerGetItems: build.query<
      FeedControllerGetItemsApiResponse,
      FeedControllerGetItemsApiArg
    >({
      query: () => ({ url: `/articles/items` }),
    }),
    feedControllerGetItemById: build.query<
      FeedControllerGetItemByIdApiResponse,
      FeedControllerGetItemByIdApiArg
    >({
      query: (queryArg) => ({ url: `/articles/items/${queryArg.id}` }),
    }),
    feedControllerGetById: build.query<
      FeedControllerGetByIdApiResponse,
      FeedControllerGetByIdApiArg
    >({
      query: (queryArg) => ({ url: `/articles/${queryArg.id}` }),
    }),
    constantControllerUpdateArticlesNumber: build.mutation<
      ConstantControllerUpdateArticlesNumberApiResponse,
      ConstantControllerUpdateArticlesNumberApiArg
    >({
      query: (queryArg) => ({
        url: `/constant/articles-number`,
        method: "POST",
        params: { number: queryArg["number"] },
      }),
    }),
  }),
  overrideExisting: false,
});
export { injectedRtkApi as v1 };
export type UsersControllerRegisterApiResponse = /** status 200  */ UserDto;
export type UsersControllerRegisterApiArg = {
  loginDto: LoginDto;
};
export type UsersControllerLoginApiResponse = /** status 200  */ {
  access_token?: string;
};
export type UsersControllerLoginApiArg = {
  loginDto: LoginDto;
};
export type UsersControllerAuthGoogleApiResponse = /** status 200  */ {
  access_token?: string;
};
export type UsersControllerAuthGoogleApiArg = {
  oAuthDto: OAuthDto;
};
export type UsersControllerLogoutApiResponse = unknown;
export type UsersControllerLogoutApiArg = void;
export type UsersControllerProfileApiResponse = /** status 200  */ UserDto;
export type UsersControllerProfileApiArg = void;
export type UsersControllerUpdateProfileApiResponse = unknown;
export type UsersControllerUpdateProfileApiArg = {
  updateUserDto: UpdateUserDto;
};
export type CryptosControllerGetAvailableCryptosApiResponse =
  /** status 200  */ CryptoDto[];
export type CryptosControllerGetAvailableCryptosApiArg = void;
export type CryptosControllerGetDashboardCryptosApiResponse =
  /** status 200  */ CryptoDto[];
export type CryptosControllerGetDashboardCryptosApiArg = void;
export type CryptosControllerGetCryptosApiResponse =
  /** status 200  */ CryptoDetailDto[];
export type CryptosControllerGetCryptosApiArg = {
  /** Comma separated list of cmids. */
  cmids?: string;
};
export type CryptosControllerUpdateCryptoApiResponse =
  /** status 201  */ UpdateCryptoDto;
export type CryptosControllerUpdateCryptoApiArg = {
  /** Cmid of the crypto. */
  cmid?: string;
  updateCryptoDto: UpdateCryptoDto;
};
export type CryptosControllerGetCryptoByIdApiResponse =
  /** status 200  */ CryptoDetailDto;
export type CryptosControllerGetCryptoByIdApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
};
export type CryptosControllerDeleteCryptoApiResponse = unknown;
export type CryptosControllerDeleteCryptoApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
};
export type CryptosControllerGetCryptoHistoryApiResponse =
  /** status 200  */ CryptoDataDto;
export type CryptosControllerGetCryptoHistoryApiArg = {
  /** Cmid of the crypto. */
  cmid: string;
  /** Period of the crypto. */
  period: string;
};
export type CryptosControllerDefaultCryptoApiResponse = unknown;
export type CryptosControllerDefaultCryptoApiArg = {
  defaultCryptoDto: DefaultCryptoDto;
};
export type FeedControllerAddFeedApiResponse = /** status 201  */ CreateFeedDto;
export type FeedControllerAddFeedApiArg = {
  createFeedDto: CreateFeedDto;
};
export type FeedControllerGetAllApiResponse = unknown;
export type FeedControllerGetAllApiArg = void;
export type FeedControllerGetItemsApiResponse =
  /** status 200  */ GetFeedItemsDto[];
export type FeedControllerGetItemsApiArg = void;
export type FeedControllerGetItemByIdApiResponse =
  /** status 200  */ GetFeedItemDto;
export type FeedControllerGetItemByIdApiArg = {
  id: string;
};
export type FeedControllerGetByIdApiResponse = unknown;
export type FeedControllerGetByIdApiArg = {
  id: string;
};
export type ConstantControllerUpdateArticlesNumberApiResponse =
  /** status 200  */ number;
export type ConstantControllerUpdateArticlesNumberApiArg = {
  number: number;
};
export type UserDto = {
  /** Email */
  email: string;
  /** Role */
  role: string;
  /** Cryptos */
  cryptos: string[];
};
export type LoginDto = {
  /** Email */
  email: string;
  /** Password */
  password: string;
};
export type OAuthDto = {
  /** Token */
  token: string;
  /** API */
  api: string;
};
export type UpdateUserDto = {
  /** Cryptos */
  cryptos: string[];
  /** Keywords */
  keywords: string[];
};
export type CryptoDto = {
  /** Id */
  id: string;
  /** Name */
  name: string;
  /** Default */
  default: boolean;
};
export type CryptoDetailDto = {
  /** Id */
  id: string;
  /** Name */
  name: string;
  /** URL to the crypto image */
  imageUrl: string;
  /** Current price */
  currentPrice: number;
  /** Opening price */
  openingPrice: number;
  /** Lowest price of the day */
  lowestPriceDay: number;
  /** Highest price of the day */
  highestPriceDay: number;
  /** Id from Coinmarketcap */
  coinmarketId: number;
  /** Is crypto available by default */
  default: boolean;
};
export type UpdateCryptoDto = {
  /** Name */
  name: string;
  /** Id from Coinmarketcap */
  coinmarketId: number;
  /** URL to the crypto image */
  imageUrl: string;
  /** Is crypto available by default */
  default: boolean;
};
export type CryptoDataDto = {
  /** Id */
  id: string;
  /** Current price */
  currentPrice: number;
  /** Opening price */
  openingPrice: number;
  /** Lowest price of the day */
  lowestPriceDay: number;
  /** Highest price of the day */
  highestPriceDay: number;
  /** Price history depending on the period */
  priceHistory: number[];
};
export type DefaultCryptoDto = {
  /** List of uuid */
  cmids: string[];
};
export type CreateFeedDto = {
  /** Name */
  name: string;
  /** URL */
  link: string;
  /** Description */
  description: string;
};
export type GetFeedItemsDto = {
  /** Article ID */
  id: string;
  /** Article Title */
  title: string;
  /** Image URL */
  image: string;
};
export type GetFeedItemDto = {
  /** Article ID */
  id: string;
  /** Article Title */
  title: string;
  /** Article body */
  content: string;
  /** Image URL */
  imageUrl: string;
  /** Article source */
  link: string;
  /** Article date */
  createdAt: string;
};
export const {
  useUsersControllerRegisterMutation,
  useUsersControllerLoginMutation,
  useUsersControllerAuthGoogleMutation,
  useUsersControllerLogoutQuery,
  useLazyUsersControllerLogoutQuery,
  useUsersControllerProfileQuery,
  useLazyUsersControllerProfileQuery,
  useUsersControllerUpdateProfileMutation,
  useCryptosControllerGetAvailableCryptosQuery,
  useLazyCryptosControllerGetAvailableCryptosQuery,
  useCryptosControllerGetDashboardCryptosQuery,
  useLazyCryptosControllerGetDashboardCryptosQuery,
  useCryptosControllerGetCryptosQuery,
  useLazyCryptosControllerGetCryptosQuery,
  useCryptosControllerUpdateCryptoMutation,
  useCryptosControllerGetCryptoByIdQuery,
  useLazyCryptosControllerGetCryptoByIdQuery,
  useCryptosControllerDeleteCryptoMutation,
  useCryptosControllerGetCryptoHistoryQuery,
  useLazyCryptosControllerGetCryptoHistoryQuery,
  useCryptosControllerDefaultCryptoMutation,
  useFeedControllerAddFeedMutation,
  useFeedControllerGetAllQuery,
  useLazyFeedControllerGetAllQuery,
  useFeedControllerGetItemsQuery,
  useLazyFeedControllerGetItemsQuery,
  useFeedControllerGetItemByIdQuery,
  useLazyFeedControllerGetItemByIdQuery,
  useFeedControllerGetByIdQuery,
  useLazyFeedControllerGetByIdQuery,
  useConstantControllerUpdateArticlesNumberMutation,
} = injectedRtkApi;
