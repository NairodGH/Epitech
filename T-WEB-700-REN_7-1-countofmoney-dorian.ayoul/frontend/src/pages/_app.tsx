import "@/styles/globals.css";
import "react-toastify/dist/ReactToastify.css";

import type { AppProps } from "next/app";
import store from "@/store/store";
import { Provider } from "react-redux";
import { ToastContainer } from "react-toastify";
import { ThemeProvider } from "@material-tailwind/react";
import { theme } from "@/styles/theme";
import { SessionProvider } from "next-auth/react";

export default function App({
  Component,
  pageProps: { session, ...pageProps },
}: AppProps) {
  return (
    <SessionProvider session={session}>
      <Provider store={store}>
        <ThemeProvider value={theme}>
          <Component {...pageProps} />
        </ThemeProvider>
        <ToastContainer />
      </Provider>
    </SessionProvider>
  );
}
