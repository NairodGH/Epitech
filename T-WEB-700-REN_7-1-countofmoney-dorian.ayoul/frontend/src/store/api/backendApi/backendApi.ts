import axiosBaseQuery from "@/axios/axiosBaseQuery";
import { createApi } from "@reduxjs/toolkit/query/react";

const backendApi = createApi({
  reducerPath: "backendApi",
  baseQuery: axiosBaseQuery({
    transformResponse: (response) => response,
  }),
  endpoints: () => ({}),
});

export default backendApi;
