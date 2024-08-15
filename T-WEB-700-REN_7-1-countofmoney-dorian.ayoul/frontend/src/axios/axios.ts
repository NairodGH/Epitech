import axios from "axios";
import { getSession } from "next-auth/react";

export const axiosInstance = axios.create({
  baseURL: process.env.NEXT_PUBLIC_BACK_URL ?? "http://localhost:4000/",
  headers: {
    "Content-Type": "application/json",
  },
});

axiosInstance.interceptors.request.use(async function (config) {
  const session = await getSession();
  const token = (session as any)?.access_token;

  if (!token) {
    return config;
  }

  config.headers.Authorization = `Bearer ${token}`;
  return config;
});
