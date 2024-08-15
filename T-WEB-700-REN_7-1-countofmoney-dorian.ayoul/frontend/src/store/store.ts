import { configureStore, ThunkAction, Action } from "@reduxjs/toolkit";
import backendApi from "./api/backendApi/backendApi";

export function makeStore() {
  return configureStore({
    reducer: {
      // Add slices here to be used in the store
      [backendApi.reducerPath]: backendApi.reducer,
    },

    middleware: (getDefaultMiddleware) =>
      getDefaultMiddleware().concat(backendApi.middleware),

    devTools: true,
  });
}

const store = makeStore();

export type AppStore = ReturnType<typeof makeStore>;
export type AppState = ReturnType<AppStore["getState"]>;
export type AppDispatch = typeof store.dispatch;

export type AppThunk<ReturnType = void> = ThunkAction<
  ReturnType,
  AppState,
  unknown,
  Action<string>
>;

export default store;
