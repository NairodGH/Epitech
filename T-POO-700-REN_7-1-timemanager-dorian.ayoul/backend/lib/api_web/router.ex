defmodule ApiWeb.Router do
  use ApiWeb, :router

  pipeline :browser do
    plug :accepts, ["html"]
    plug :fetch_session
    plug :fetch_live_flash
    plug :put_root_layout, html: {ApiWeb.Layouts, :root}
    plug :protect_from_forgery
    plug :put_secure_browser_headers
  end

  pipeline :api do
    plug :accepts, ["json"]
  end

  pipeline :api_employee do
    # plug ApiWeb.JWTMiddlewareEmployee
  end

  pipeline :api_manager do
    # plug ApiWeb.JWTMiddlewareManager
  end

  pipeline :api_admin do
    # plug ApiWeb.JWTMiddlewareAdmin
  end

  scope "/", ApiWeb do
    pipe_through :browser

    get "/", PageController, :home
  end

  # scope no auth
  scope "/api", ApiWeb do
    pipe_through :api

    post "/users/login", UserController, :login
    post "/users", UserController, :create
  end

  # scope employee
  scope "/api", ApiWeb do
    pipe_through [:api, :api_employee]

    get "/users/:id", UserController, :show
    put "/users/:id", UserController, :update
    delete "/users/:id", UserController, :delete
    get "/users/:user_id/clocks", ClockController, :show_user_clocks

    resources "/working_times", WorkingTimeController

    get "/clocks/:id", ClockController, :show
    post "/clocks/:id", ClockController, :create
    post "/clocks/manual", ClockController, :create_with_data
    put "/clocks/:id", ClockController, :update
    delete "/clocks/:id", ClockController, :delete
    resources "/clocks", ClockController
  end

  # scope manager
  scope "/api", ApiWeb do
    pipe_through [:api, :api_manager]

    # get "/users:params", UserController, :find
    put "/users/:id/team", UserController, :update_team
    get "/users/:id/teams", TeamController, :show_teams

    get "/teams/:team_id/users", UserController, :show_users
    get "/teams/:team_id/clocks", ClockController, :show_team_clocks
    resources "/teams", TeamController, except: [:index]
  end

  # scope admin
  scope "/api", ApiWeb do
    pipe_through [:api, :api_admin]

    get "/users", UserController, :index
    get "/teams", TeamController, :index
    get "/clocks", ClockController, :index
  end

  scope "/api/swagger" do
    forward "/", PhoenixSwagger.Plug.SwaggerUI,
      otp_app: :api,
      swagger_file: "swagger.json"
  end

  def swagger_info do
    %{
      schemes: ["http", "https", "ws", "wss"],
      info: %{
        version: "1.0",
        title: "CGT-U",
        description: "API Documentation for CGT-U",
        contact: %{
          name: "The batman",
          email: "bruce.wayne@gmail.com"
        }
      },
      securityDefinitions: %{
        Bearer: %{
          type: "apiKey",
          name: "Authorization",
          description:
          "API Token must be provided via `Authorization: Bearer ` header",
          in: "header"
        }
      },
      consumes: ["application/json"],
      produces: ["application/json"],
      # tags: [
        # %{name: "Users", description: "User resources"},
      # ]
    }
  end
end
