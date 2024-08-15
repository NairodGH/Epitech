defmodule ApiWeb.UserController do
  use ApiWeb, :controller
  use PhoenixSwagger

  alias Api.Users
  alias Api.Users.User

  alias Api.Teams

  alias Api.WorkingTimes

  alias Api.Clocks

  action_fallback(ApiWeb.FallbackController)

  swagger_path :login do
    post("/api/users/login")
    description("Login user")

    parameters do
      user(:body, :user, "User params", required: true, schema: User)
    end

    response(:ok, "Success")
  end

  def login(conn, %{"user" => user_params}) do
    with {:ok, token} <- Users.login_user(user_params) do
      conn
      |> put_status(:created)
      |> put_resp_header("location", "/api/users/#{token}")
      |> text(token)
    else
      {:error, reason} ->
        conn
        |> put_status(:unauthorized)
        |> text(reason)
    end
  end

  swagger_path :index do
    get("/api/users")
    description("List of users")
    security([%{Bearer: []}])
    response(:ok, "Success")
  end

  def index(conn, _params) do
    users = Users.list_users()
    render(conn, :index, users: users)
  end

  swagger_path :find do
    get("/api/users:params")
    description("Find users by params (max: 1)")
    security([%{Bearer: []}])

    parameters do
      team_id(:query, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
      role(:query, :string, "Role", example: "Manager")
    end

    response(:ok, "Success")
  end

  def find(conn, %{"team_id" => team_id} = params) do
    users = Users.find_users_by_team!(team_id)
    render(conn, :index, users: users, params: params)
  end

  swagger_path :show_users do
    get("/api/teams/:id/users")
    description("Show users in the team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "Team id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show_users(conn, %{"team_id" => team_id}) do
    users = Teams.get_users_from_team!(team_id)
    render(conn, :index, users: users)
  end

  def find(conn, %{"role" => role} = params) do
    users = Users.find_users_by_role!(role)
    render(conn, :index, users: users, params: params)
  end

  def find(conn, _params) do
    users = Users.list_users()
    render(conn, :index, users: users)
  end

  swagger_path :create do
    post("/api/users")
    description("Create user")

    parameters do
      user(:body, :user, "User params", required: true, schema: User)
    end

    response(:ok, "Success")
  end

  def create(conn, %{"user" => user_params}) do
    case Users.find_user_by_email!(user_params["email"]) do
      nil ->
        case Users.create_user(user_params) do
          {:ok, user} ->
            conn
            |> put_status(:created)
            |> put_resp_header("location", ~p"/api/users/#{user}")
            |> text(
              Api.Token.generate_and_sign!(
                %{"user_id" => user.id, "role" => user.role},
                Api.Token.get_signer()
              )
            )

          # TODO: this error make the api crashes
          {:error, reason} ->
            IO.inspect(reason)

            conn
            |> put_status(:unprocessable_entity)
            |> render("error.json", errors: [reason])
        end

      _ ->
        conn
        |> put_status(:conflict)
        |> text("User already exists")
    end
  end

  swagger_path :show do
    get("/api/users/:id")
    description("Show user")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "User id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def show(conn, %{"id" => id}) do
    user = Users.get_user!(id)
    render(conn, :show, user: user)
  end

  swagger_path :update do
    put("/api/users/:id")
    description("Update user")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "User id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
      user(:body, :user, "User params", required: true, schema: User)
    end

    response(:ok, "Success")
  end

  def update(conn, %{"id" => id, "user" => user_params}) do
    user = Users.get_user!(id)

    with {:ok, %User{} = user} <- Users.update_user(user, user_params) do
      render(conn, :show, user: user)
    end
  end

  swagger_path :update_team do
    put("/api/users/:id/team")
    description("Update user team")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "User id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
      team_id(:body, :string, "Team id", example: "3e9f92b0-4985-46ec-bb64-95eb82699790")
    end
  end

  def update_team(conn, %{"id" => id, "team" => team_id}) do
    user = Users.get_user!(id)
    _team = Teams.get_team!(team_id)

    with {:ok, %User{} = user} <- Users.update_team(user, team_id) do
      render(conn, :show, user: user)
    end
  end

  swagger_path :delete do
    PhoenixSwagger.Path.delete("/api/users/:id")
    description("Delete user")
    security([%{Bearer: []}])

    parameters do
      id(:path, :string, "User id", example: "bd6b8444-6aa8-41ea-94c7-b438f895fb75")
    end

    response(:ok, "Success")
  end

  def delete(conn, %{"id" => id}) do
    user = Users.get_user!(id)

    # TODO: check error
    WorkingTimes.delete_user_working_time(id)
    Clocks.delete_user_clocks(id)
    Users.delete_user(user)

    send_resp(conn, :no_content, "")
  end
end
