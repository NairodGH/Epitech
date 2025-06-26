import axios, { AxiosRequestConfig, AxiosResponse } from "axios";
import { useState, useCallback } from "react";

interface FetchApiProps {
    url: string;
    method?: 'GET' | 'POST';
    data?: never;
    options?: AxiosRequestConfig;
}

export const useFetchApi = ({ url, method = 'GET', options = {} }: FetchApiProps) => {
    const [responseData, setResponseData] = useState(null);
    const [isLoading, setIsLoading] = useState(false);
    const [error, setError] = useState<{ message: string } | null>(null);

    const fetchData = useCallback(async (customData?: any) => {
        setIsLoading(true);
        setError(null);

        try {
            const config: AxiosRequestConfig = {
                url,
                method,
                data: customData,
                ...options,
            };

            if (customData instanceof FormData) {
                config.headers = { ...config.headers, 'Content-Type': 'multipart/form-data' };
            }

            const response: AxiosResponse = await axios(config);
            setResponseData(response.data);
            return response.data;
        } catch (err: any) {
            const detail = err.response?.data?.detail || err.message || "An error occurred";
            let parsedMessage = detail;
            try {
                if (typeof detail === "string") {
                    if (detail.startsWith("{") && detail.endsWith("}")) {
                        const parsedDetail = JSON.parse(
                            detail.replace(/'/g, '"') 
                        );
                        if (parsedDetail.message) {
                            parsedMessage = parsedDetail.message;
                        }
                    } else {
                        const jsonMatch = detail.match(/["']message["']:\s*["'](.*?)["']/);
                        if (jsonMatch) parsedMessage = jsonMatch[1];
                    }
                }
            } catch {
                parsedMessage = detail;
            }
        
            setError({ message: parsedMessage });
            throw { message: parsedMessage };
        }
         finally {
            setIsLoading(false);
        }
    }, [url, method, options]);

    return { data: responseData, isLoading, error, refetch: fetchData, setError };
};
