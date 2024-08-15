defmodule ApiWeb.TeamController do
  use ApiWeb, :controller
  use PhoenixSwagger

  alias Api.Teams
  alias Api.Teams.Team

  alias Api.Users

  action_fallback(ApiWeb.FallbackController)

  swagger_path :index do
    get("/api/teams")
    description("List of teams")
    security([%{Bearer: []}])
    response(:ok, "Success")
  end

  def index(conn, _params) do
    teams = Teams.list_teams()
    render(conn, :index, teams: teams)
  end

  swagger_path :create do
    post("/api/teams")
    description("Create team")
    security([%{Bearer: []}])

    parameters do
      team(:body, :team, "Team params", required: true, schema: Team)
    end

    response(:ok, "Success")
  end

  def create(conn, %{"team" => team_params}) do
    if team_params["manager"] == nil do
      conn
      |> put_status(:unprocessable_entity)
      |> text("Manager is required")
    else
      if team_params["name"] == nil do
        conn
        |> put_status(:unprocessable_entity)
        |> text("Name is required")
      end

      _user = Users.get_user!(team_params["manager"])

      with {:ok, %Team{} = team} <- Teams.create_team(team_params) do
        conn
        |> put_status(:created)
        |> put_resp_header("location", ~p"/api/teams/#{team}")
        |> render(:show, team: team)
      end
    end
  end

  swagger_path :show do
    get("/api/teams/:id")
    description("Show team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show(conn, %{"id" => id}) do
    team = Teams.get_team!(id)
    render(conn, :show, team: team)
  end

  swagger_path :show_teams do
    get("/api/teams")
    description("List of teams")
    security([%{Bearer: []}])
    response(:ok, "Success")
  end

  def show_teams(conn, %{"id" => id}) do
    teams = Teams.get_teams_from_user!(id)
    render(conn, :index, teams: teams)
  end

  swagger_path :update do
    put("/api/teams/:id")
    description("Update team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
      team(:body, :team, "Team params", required: true, schema: Team)
    end

    response(:ok, "Success")
  end

  def update(conn, %{"id" => id, "team" => team_params}) do
    team = Teams.get_team!(id)

    with {:ok, %Team{} = team} <- Teams.update_team(team, team_params) do
      render(conn, :show, team: team)
    end
  end

  swagger_path :delete do
    PhoenixSwagger.Path.delete("/api/teams/:id")
    description("Delete team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def delete(conn, %{"id" => id}) do
    team = Teams.get_team!(id)

    with {:ok, %Team{}} <- Teams.delete_team(team) do
      send_resp(conn, :no_content, "")
    end
  end
end
