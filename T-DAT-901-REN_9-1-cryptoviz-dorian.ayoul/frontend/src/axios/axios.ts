import axios from "axios";

export const axiosInstance = axios.create({
  baseURL: process.env.NEXT_PUBLIC_BACK_URL ?? "http://localhost:4000/",
  headers: {
    "Content-Type": "application/json",
  },
});
