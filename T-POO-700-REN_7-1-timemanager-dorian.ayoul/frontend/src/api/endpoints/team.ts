import { DataWrapper } from "@/types/genericTypes";
import { instance } from "@/api/axios/instance";
import { Clock } from "./clock";
import { User } from "./user";

export type Team = {
  id?: string;
  name?: string;
  manager?: string;
};

async function teams() {
  const resp = await instance.get<DataWrapper<Team[]>>("/teams");
  return resp.data;
}

async function teamShow({ id }: { id: string }) {
  const resp = await instance.get<DataWrapper<Team>>(`/teams/${id}`);
  return resp.data;
}

async function teamUsers({ teamId }: { teamId: string }) {
  const resp = await instance.get<DataWrapper<User[]>>(`/teams/${teamId}/users`);
  return resp.data;
}

async function teamClocks({ id }: { id: string }) {
  const resp = await instance.get<DataWrapper<Clock[]>>(`/teams/${id}/clocks`);
  return resp.data;
}

async function teamCreate({ name, manager }: Team) {
  const resp = await instance.post<{ team: Team }, DataWrapper<Team>>("/teams", { team: { name, manager } });
  return resp.data;
}

async function teamUpdate({ id, name, manager }: Team) {
  const resp = await instance.put<{ team: Team }, DataWrapper<Team>>(`/teams/${id}`, { team: { name, manager } });
  return resp.data;
}

async function teamDelete({ id }: { id: string }) {
  const resp = await instance.delete<DataWrapper<Team>>(`/teams/${id}`);
  return resp.data;
}

export { teams, teamShow, teamUsers, teamClocks, teamCreate, teamUpdate, teamDelete };
