defmodule ApiWeb.WorkingTimeController do
  use ApiWeb, :controller
  use PhoenixSwagger

  alias Api.WorkingTimes
  alias Api.WorkingTimes.WorkingTime

  alias Api.Users

  action_fallback(ApiWeb.FallbackController)

  swagger_path :index do
    get("/api/working_times")
    description("List of working times")
    security([%{Bearer: []}])
    response(:ok, "Success")
  end

  def index(conn, _params) do
    workingtimes = WorkingTimes.list_workingtimes()
    render(conn, :index, workingtimes: workingtimes)
  end

  swagger_path :create do
    post("/api/working_times")
    description("Create working time")
    security([%{Bearer: []}])

    parameters do
      working_time(:body, :working_time, "Working time params",
        required: true,
        schema: WorkingTime
      )
    end

    response(:ok, "Success")
  end

  def create(conn, %{"working_time" => working_time_params}) do
    if working_time_params["user"] == nil do
      conn
      |> put_status(:conflict)
      |> text("User is required")
      |> halt()
    else
      _user = Users.get_user!(working_time_params["user"])
      working_time = WorkingTimes.get_user_working_time!(working_time_params["user"])

      case working_time do
        nil ->
          with {:ok, %WorkingTime{} = working_time} <-
                 WorkingTimes.create_working_time(working_time_params) do
            conn
            |> put_status(:created)
            |> render(:show, working_time: working_time)
          end

        _ ->
          conn
          |> put_status(:conflict)
          |> text("Working time already exists")
      end
    end
  end

  swagger_path :show do
    get("/api/working_times/:id")
    description("Show working time")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Working time id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show(conn, %{"id" => id}) do
    working_time = WorkingTimes.get_working_time!(id)
    render(conn, :show, working_time: working_time)
  end

  swagger_path :update do
    put("/api/working_times/:id")
    description("Update working time")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Working time id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")

      working_time(:body, :working_time, "Working time params",
        required: true,
        schema: WorkingTime
      )
    end

    response(:ok, "Success")
  end

  def update(conn, %{"id" => id, "working_time" => working_time_params}) do
    working_time = WorkingTimes.get_working_time!(id)

    with {:ok, %WorkingTime{} = working_time} <-
           WorkingTimes.update_working_time(working_time, working_time_params) do
      render(conn, :show, working_time: working_time)
    end
  end

  swagger_path :delete do
    PhoenixSwagger.Path.delete("/api/working_times/:id")
    description("Delete working time")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Working time id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def delete(conn, %{"id" => id}) do
    working_time = WorkingTimes.get_working_time!(id)

    with {:ok, %WorkingTime{}} <- WorkingTimes.delete_working_time(working_time) do
      send_resp(conn, :no_content, "")
    end
  end
end
