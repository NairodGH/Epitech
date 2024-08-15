import { DataWrapper } from "@/types/genericTypes";
import { instance } from "@/api/axios/instance";

export type WorkingTime = {
  id?: string;
  start?: string;
  end?: string;
  user?: string;
};

async function workingTimes() {
  const resp = await instance.get<DataWrapper<WorkingTime[]>>("/working_times");
  return resp.data;
}

async function workingTimeShow({ id }: { id: string }) {
  const resp = await instance.get<DataWrapper<WorkingTime>>(`/working_times/${id}`);
  return resp.data;
}

async function workingTimeCreate({ start, end, user }: WorkingTime) {
  const resp = await instance.post<{ workingTime: WorkingTime }, DataWrapper<WorkingTime>>("/working_times", {
    workingTime: { start, end, user },
  });
  return resp.data;
}

async function workingTimeUpdate({ id, start, end, user }: WorkingTime) {
  const resp = await instance.put<{ workingTime: WorkingTime }, DataWrapper<WorkingTime>>(`/working_times/${id}`, {
    workingTime: { start, end, user },
  });
  return resp.data;
}

async function workingTimeDelete({ id }: { id: string }) {
  const resp = await instance.delete<DataWrapper<WorkingTime>>(`/working_times/${id}`);
  return resp.data;
}

export { workingTimes, workingTimeShow, workingTimeCreate, workingTimeUpdate, workingTimeDelete };
