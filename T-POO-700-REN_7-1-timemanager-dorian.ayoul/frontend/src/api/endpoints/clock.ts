import { DataWrapper } from "@/types/genericTypes";
import { instance } from "@/api/axios/instance";

export type Clock = {
  id?: string;
  start?: string;
  end?: string;
  user?: string;
};

async function clocks() {
  const resp = await instance.get<DataWrapper<Clock[]>>("/clocks");
  return resp.data;
}

async function clockShow({ id }: { id: string }) {
  const resp = await instance.get<DataWrapper<Clock>>(`/clocks/${id}`);
  return resp.data;
}

async function clockCreate({ user }: { user: string }) {
  const resp = await instance.post<{ clock: Clock }, DataWrapper<Clock>>("/clocks", {
    clock: { user },
  });
  return resp.data;
}

async function clockUpdate({ id, start, end, user }: Clock) {
  const resp = await instance.put<{ clock: Clock }, DataWrapper<Clock>>(`/clocks/${id}`, {
    clock: { start, end, user },
  });
  return resp.data;
}

async function clockDelete({ id }: { id: string }) {
  const resp = await instance.delete<DataWrapper<Clock>>(`/clocks/${id}`);
  return resp.data;
}

export { clocks, clockShow, clockCreate, clockUpdate, clockDelete };
