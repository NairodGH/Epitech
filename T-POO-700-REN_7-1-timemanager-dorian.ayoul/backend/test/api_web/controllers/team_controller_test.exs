defmodule ApiWeb.TeamControllerTest do
  use ApiWeb.ConnCase

  @token "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJKb2tlbiIsImV4cCI6MzY5OTUzMzgzOSwiaWF0IjoxNjk5NTI2NjM5LCJpc3MiOiJKb2tlbiIsImp0aSI6IjJ1YXVzdWI4dHJqaTNwYjhzODAwMDAwMyIsIm5iZiI6MTY5OTUyNjYzOSwicm9sZSI6InVzZXIiLCJ1c2VyX2lkIjoiMDM5YjZiMWYtZjJmNy00MWE3LThjYjMtYjY5NDdiZTAxZWZkIn0.S3XWc2BB3BXFK4flPcgJzqA41gyMStJagiBjrBtQ2TU"

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all teams", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> get(~p"/api/teams")

      assert json_response(conn, 200)["data"] == []
    end
  end

  # describe "create team" do
  # test "renders team when data is valid", %{conn: conn} do
  # conn =
  # conn
  # |> put_req_header("authorization", "Bearer #{@token}")
  # |> post(~p"/api/teams", team: @create_attrs)
  #
  # assert %{"id" => id} = json_response(conn, 201)["data"]
  #
  # conn = get(conn, ~p"/api/teams/#{id}")
  #
  # assert %{
  #  "id" => ^id,
  #  "name" => "some name",
  #  } = json_response(conn, 200)["data"]
  # end

  # test "renders errors when data is invalid", %{conn: conn} do
  # conn =
  # conn
  # |> put_req_header("authorization", "Bearer #{@token}")
  # |> post(~p"/api/teams", team: @invalid_attrs)
  #
  # assert json_response(conn, 422)["errors"] != %{}
  # end
  # end

  # describe "update team" do
  #   setup [:create_team]

  #   test "renders team when data is valid", %{conn: conn, team: %Team{id: id} = team} do
  #     conn = put(conn, ~p"/api/teams/#{team}", team: @update_attrs)
  #     assert %{"id" => ^id} = json_response(conn, 200)["data"]

  #     conn = get(conn, ~p"/api/teams/#{id}")

  #     assert %{
  #              "id" => ^id,
  #              "name" => "some updated name",
  #              "manager" => "e0acf741-3c2c-449b-8a49-8b121a5a63e8"
  #            } = json_response(conn, 200)["data"]
  #   end

  #   test "renders errors when data is invalid", %{conn: conn, team: team} do
  #     conn = put(conn, ~p"/api/teams/#{team}", team: @invalid_attrs)
  #     assert json_response(conn, 422)["errors"] != %{}
  #   end
  # end

  # describe "delete team" do
  #   setup [:create_team]

  #   test "deletes chosen team", %{conn: conn, team: team} do
  #     conn = delete(conn, ~p"/api/teams/#{team}")
  #     assert response(conn, 204)

  #     assert_error_sent(404, fn ->
  #       get(conn, ~p"/api/teams/#{team}")
  #     end)
  #   end
  # end

  # defp create_team(_) do
  # team = team_fixture()
  # %{team: team}
  # end
end
