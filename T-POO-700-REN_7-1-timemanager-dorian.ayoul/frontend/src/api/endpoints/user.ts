import { DataWrapper } from "@/types/genericTypes";
import { instance } from "@/api/axios/instance";
import { Clock } from "./clock";

export type User = {
  id?: string;
  email?: string;
  firstname?: string;
  lastname?: string;
  team?: string;
  role?: string;
};

export type UserAction = {
  email?: string;
  password?: string;
  firstname?: string;
  lastname?: string;
};

async function userLogin({ email, password }: { email: string; password: string }) {
  const resp = await instance.post<UserAction, string>("/users/login", {
    user: { email, password },
  });
  return resp;
}

async function userUpdateTeam({ userId, teamId }: { userId: string; teamId: string }) {
  const resp = await instance.put<{ team: string }, DataWrapper<User>>(`/users/${userId}/team`, { team: teamId });
  return resp.data;
}

async function usersFindByRole({ role }: { role: string }) {
  const resp = await instance.get<DataWrapper<User[]>>(`/users?role=${role}`);
  return resp.data;
}

async function userShowTeams({ manager }: { manager: string }) {
  const resp = await instance.get<DataWrapper<User[]>>(`/users/${manager}/teams`);
  return resp.data;
}

async function users() {
  const resp = await instance.get<DataWrapper<User[]>>("/users");
  return resp.data;
}

async function userShow({ id }: { id: string }) {
  const resp = await instance.get<DataWrapper<User>>(`/users/${id}`);
  return resp.data;
}

async function userCreate({ email, password, firstname, lastname }: UserAction) {
  const resp = await instance.post<{ user: UserAction }, string>("/users", {
    user: { email, password, firstname, lastname },
  });
  return resp;
}

export type UserUpdate = {
  id?: string;
  email?: string;
  firstname?: string;
  lastname?: string;
  password?: string;
  team?: string;
  role?: string;
};

async function userUpdate({ id, email, password, firstname, lastname, role, team }: UserUpdate) {
  const resp = await instance.put<{ user: UserUpdate }, DataWrapper<User>>(`/users/${id}`, {
    user: {
      id,
      email,
      password,
      firstname,
      lastname,
      role,
      team,
    },
  });
  return resp.data;
}

async function userDelete({ id }: { id: string }) {
  const resp = await instance.delete(`/users/${id}`);
  return resp.data;
}

async function userClocks({ userId }: { userId: string }) {
  const resp = await instance.get<DataWrapper<Clock[]>>(`/users/${userId}/clocks`);
  return resp.data;
}

export {
  userLogin,
  userUpdateTeam,
  usersFindByRole,
  userShowTeams,
  users,
  userShow,
  userCreate,
  userUpdate,
  userDelete,
  userClocks,
};
