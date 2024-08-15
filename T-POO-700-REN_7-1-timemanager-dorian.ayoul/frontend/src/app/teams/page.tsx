"use client";

import { teams } from "@/api/endpoints/team";
import { userShowTeams } from "@/api/endpoints/user";
import TeamsTileView from "@/components/TeamsTileView";
import Wrapper from "@/components/Wrapper";
import { useJWT } from "@/hooks/useJWT";
import { useNotify } from "@/hooks/useNotify";
import { useQuery } from "react-query";

function ManagerTeams() {
  const { id } = useJWT();
  const notify = useNotify();

  const { data: teamsData } = useQuery({
    queryKey: "teams/personnalTeams",
    queryFn: () => userShowTeams({ manager: id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    enabled: !!id,
  });

  return (
    <Wrapper>
      <div className="flex flex-col gap-5 p-5">
        <p className="text-3xl">Teams</p>
        <TeamsTileView teams={teamsData?.data ?? []} />
      </div>
    </Wrapper>
  );
}

function AdminTeams() {
  const { data: teamsData } = useQuery({
    queryKey: "teams/teams",
    queryFn: teams,
  });

  return (
    <Wrapper>
      <div className="flex flex-col gap-5 p-5">
        <div className="text-center text-3xl">Teams</div>
        <TeamsTileView teams={teamsData?.data ?? []} />
      </div>
    </Wrapper>
  );
}

export default function Teams() {
  const { role } = useJWT();

  if (role === "admin") {
    return <AdminTeams />;
  }
  return <ManagerTeams />;
}
