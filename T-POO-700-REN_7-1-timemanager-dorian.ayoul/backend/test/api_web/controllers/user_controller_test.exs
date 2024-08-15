defmodule ApiWeb.UserControllerTest do
  use ApiWeb.ConnCase

  @create_attrs %{
    password: "password",
    role: "Manager",
    firstname: "mama",
    lastname: "ouhouhou",
    email: "test@mail.com"
  }
  @token "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJKb2tlbiIsImV4cCI6MzY5OTUzMzgzOSwiaWF0IjoxNjk5NTI2NjM5LCJpc3MiOiJKb2tlbiIsImp0aSI6IjJ1YXVzdWI4dHJqaTNwYjhzODAwMDAwMyIsIm5iZiI6MTY5OTUyNjYzOSwicm9sZSI6InVzZXIiLCJ1c2VyX2lkIjoiMDM5YjZiMWYtZjJmNy00MWE3LThjYjMtYjY5NDdiZTAxZWZkIn0.S3XWc2BB3BXFK4flPcgJzqA41gyMStJagiBjrBtQ2TU"

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all users", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> get(~p"/api/users")

      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create user" do
    test "renders user when data is valid", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> post(~p"/api/users", user: @create_attrs)

      assert text_response(conn, 201) != ""

      conn = get(conn, ~p"/api/users")

      assert json_response(conn, 200)["data"] != []
    end

    # test "renders errors when data is invalid", %{conn: conn} do
      # conn = post(conn, ~p"/api/users", user: @invalid_attrs)
      # assert json_response(conn, 422)["errors"] != %{}
    # end
  end

  # describe "update user" do
  # test "renders errors when data is invalid", %{conn: conn, user: user} do
  # conn =
  # conn
  # |> put_req_header("authorization", "Bearer #{@token}")
  # |> put(~p"/api/users/#{user}", user: %{firstname: nil})
  #
  # assert json_response(conn, 422)["errors"] != %{}
  # end
  # end
end
