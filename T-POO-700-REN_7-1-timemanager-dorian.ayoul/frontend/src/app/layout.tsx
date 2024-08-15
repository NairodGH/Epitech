"use client";

import { Inter } from "next/font/google";
import { QueryClient, QueryClientProvider } from "react-query";
import "./globals.css";
import { ReactNode } from "react";

const inter = Inter({ subsets: ["latin"] });

export default function RootLayout({ children }: { readonly children: ReactNode }) {
  const queryClient = new QueryClient();

  return (
    <QueryClientProvider client={queryClient}>
      <html lang="en">
        <head>
          <title>CGT-U</title>
          <link rel="icon" type="image/x-icon" href="/assets/icon.ico" />
          <link
            rel="stylesheet"
            type="text/css"
            href="https://cdn3.devexpress.com/jslib/23.1.5/css/dx.material.blue.dark.css"
          />
        </head>
        <body className={inter.className + "dx-viewport dx-device-desktop dx-device-generic"}>{children}</body>
      </html>
    </QueryClientProvider>
  );
}
