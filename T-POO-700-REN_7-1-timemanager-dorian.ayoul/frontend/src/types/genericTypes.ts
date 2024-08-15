export type ClockData = {
  date: string;
  start: string;
  end: string;
  difference: string;
  startAverage: string;
  endAverage: string;
  differenceAverage: string;
};

export type DataWrapper<T> = {
  data: T;
};

export type Roles = "employee" | "manager" | "admin";
