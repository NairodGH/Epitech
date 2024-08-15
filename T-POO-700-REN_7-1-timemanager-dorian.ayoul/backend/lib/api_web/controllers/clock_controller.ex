defmodule ApiWeb.ClockController do
  use ApiWeb, :controller
  use PhoenixSwagger

  alias Api.Clocks
  alias Api.Clocks.Clock

  alias Api.Teams

  action_fallback(ApiWeb.FallbackController)

  swagger_path :index do
    get("/api/clocks")
    description("List of clocks")
    security([%{Bearer: []}])
    response(:ok, "Success")
  end

  def index(conn, _params) do
    clocks = Clocks.list_clocks()
    render(conn, :index, clocks: clocks)
  end

  swagger_path :create_with_data do
    post("/api/clocks/create_with_data")
    description("Create clock with data")
    security([%{Bearer: []}])

    parameters do
      clock(:body, :clock, "Clock params", required: true, schema: Clock)
    end

    response(:ok, "Success")
  end

  def create_with_data(conn, %{"clock" => clock_params}) do
    with {:ok, %Clock{} = clock} <- Clocks.create_clock(clock: clock_params) do
      conn
      |> put_status(:created)
      |> render(:show, clock: clock)
    end
  end

  swagger_path :create do
    post("/api/clocks")
    description("Create clock")
    security([%{Bearer: []}])

    parameters do
      clock(:body, :clock, "Clock params", required: true, schema: Clock)
    end

    response(:ok, "Success")
  end

  def create(conn, %{"clock" => clock_params}) do
    is_finished_clock = Clocks.get_not_finished_clock!(clock_params["user"])
    date = DateTime.utc_now()

    if is_finished_clock == nil do
      with {:ok, %Clock{} = clock} <-
             Clocks.create_clock(%{start: date, user: clock_params["user"]}) do
        conn
        |> put_status(:created)
        |> render(:show, clock: clock)
      end
    else
      with {:ok, %Clock{} = clock} <-
             Clocks.update_clock(is_finished_clock, %{end: date, status: true}) do
        conn
        |> put_status(:created)
        |> render(:show, clock: clock)
      end
    end
  end

  swagger_path :show do
    get("/api/clocks/:id")
    description("Show clock")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Clock id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show(conn, %{"id" => id}) do
    clock = Clocks.get_clock!(id)
    render(conn, :show, clock: clock)
  end

  swagger_path :show_user_clocks do
    get("/api/clocks/user/:user_id")
    description("Show clocks for a user")
    security([%{Bearer: []}])

    parameters do
      user_id(:path, :string, "User id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show_user_clocks(conn, %{"user_id" => user_id}) do
    clocks = Clocks.get_user_clocks!(user_id)
    render(conn, :index, clocks: clocks)
  end

  swagger_path :show_team_clocks do
    get("/api/clocks/team/:team_id")
    description("Show clocks in the team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show_team_clocks(conn, %{"team_id" => team_id}) do
    clocks = Teams.get_clocks_from_team!(team_id)
    render(conn, :index, clocks: clocks)
  end

  swagger_path :update do
    put("/api/clocks/:id")
    description("Update clock")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Clock id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
      clock(:body, :clock, "Clock params", required: true, schema: Clock)
    end

    response(:ok, "Success")
  end

  def update(conn, %{"id" => id, "clock" => clock_params}) do
    clock = Clocks.get_clock!(id)

    with {:ok, %Clock{} = clock} <- Clocks.update_clock(clock, clock_params) do
      render(conn, :show, clock: clock)
    end
  end

  swagger_path :delete do
    PhoenixSwagger.Path.delete("/api/clocks/:id")
    description("Delete clock")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Clock id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def delete(conn, %{"id" => id}) do
    clock = Clocks.get_clock!(id)

    with {:ok, %Clock{}} <- Clocks.delete_clock(clock) do
      send_resp(conn, :no_content, "")
    end
  end
end
