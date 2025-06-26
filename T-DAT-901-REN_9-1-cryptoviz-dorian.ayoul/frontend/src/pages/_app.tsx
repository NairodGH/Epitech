import "@/styles/globals.css";
import "react-toastify/dist/ReactToastify.css";

import type { AppProps } from "next/app";
import store from "@/store/store";
import { Provider } from "react-redux";
import { ToastContainer } from "react-toastify";
import { ThemeProvider } from "@material-tailwind/react";
import { theme } from "@/styles/theme";

export default function App({ Component, pageProps: { ...pageProps } }: AppProps) {
  return (
    <Provider store={store}>
      <ThemeProvider value={theme}>
        <Component {...pageProps} />
      </ThemeProvider>
      <ToastContainer />
    </Provider>
  );
}
