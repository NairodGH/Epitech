import type { BaseQueryApi, BaseQueryFn } from "@reduxjs/toolkit/query";
import type { AxiosRequestConfig, AxiosRequestHeaders } from "axios";
import { axiosInstance } from "./axios";
import Axios from "axios";

export interface AxiosBaseQueryArgs<Meta, Response = { httpStatus: 200 }> {
  meta?: Meta;
  prepareHeaders?: (
    headers: AxiosRequestHeaders,
    api: BaseQueryApi
  ) => AxiosRequestHeaders;
  transformResponse?: (response: Response) => unknown;
}

export interface ServiceExtraOptions {
  authRequired?: boolean;
}

const getRequestConfig = (args: string | AxiosRequestConfig) => {
  if (typeof args === "string") {
    return { url: args };
  }

  return args;
};

const axiosBaseQuery = <
  Args extends AxiosRequestConfig | string = AxiosRequestConfig,
  Result = unknown,
  DefinitionExtraOptions extends ServiceExtraOptions = Record<string, unknown>,
  Meta = Record<string, unknown>
>({ meta, transformResponse }: AxiosBaseQueryArgs<Meta> = {}): BaseQueryFn<
  Args,
  Result,
  unknown,
  DefinitionExtraOptions,
  Meta
> => {
  return async (args, api, extraOptions) => {
    try {
      const requestConfig = getRequestConfig(args);
      const result = await axiosInstance({
        ...requestConfig,
        data: (requestConfig as any).body,
        signal: api.signal,
        ...extraOptions,
      });

      return {
        data: transformResponse ? transformResponse(result.data) : result.data,
      };
    } catch (err) {
      if (!Axios.isAxiosError(err)) {
        return {
          error: err,
          meta,
        };
      }

      return {
        error: {
          status: err.response?.status,
          data: err.response?.data || err.message,
        },
        meta,
      };
    }
  };
};

export default axiosBaseQuery;
