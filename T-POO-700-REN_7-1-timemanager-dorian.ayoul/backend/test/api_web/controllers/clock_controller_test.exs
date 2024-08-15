defmodule ApiWeb.ClockControllerTest do
  use ApiWeb.ConnCase

  @token "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJKb2tlbiIsImV4cCI6MzY5OTUzMzgzOSwiaWF0IjoxNjk5NTI2NjM5LCJpc3MiOiJKb2tlbiIsImp0aSI6IjJ1YXVzdWI4dHJqaTNwYjhzODAwMDAwMyIsIm5iZiI6MTY5OTUyNjYzOSwicm9sZSI6InVzZXIiLCJ1c2VyX2lkIjoiMDM5YjZiMWYtZjJmNy00MWE3LThjYjMtYjY5NDdiZTAxZWZkIn0.S3XWc2BB3BXFK4flPcgJzqA41gyMStJagiBjrBtQ2TU"

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all clocks", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> get(~p"/api/clocks")

      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create clock" do
    # test "renders clock when data is valid", %{conn: conn} do
    #   conn =
    #     conn
    #     |> put_req_header("authorization", "Bearer #{@token}")
    #     |> post(
    #       ~p"/api/clocks",
    #       %{"clock" => @create_attrs}
    #     )

    #   assert %{"id" => id} = json_response(conn, 201)["data"]

    #   conn =
    #     conn
    #     |> put_req_header("authorization", "Bearer #{@token}")
    #     |> get(conn, ~p"/api/clocks/#{id}")

    #   assert %{
    #            "id" => ^id,
    #            "end" => "2023-10-24T15:13:00Z",
    #            "start" => "2023-10-24T15:13:00Z",
    #            "status" => true
    #          } = json_response(conn, 200)["data"]
    # end

    #   test "renders errors when data is invalid", %{conn: conn} do
    #     conn =
    #       conn
    #       |> put_req_header("authorization", "Bearer #{@token}")
    #       |> post(
    #         ~p"/api/clocks",
    #         %{"clock" => %{user: nil}}
    #       )
    #     assert json_response(conn, 422)["errors"] != %{}
    #   end
  end

  # describe "update clock" do
    # setup [:create_clock]

    # test "renders clock when data is valid", %{conn: conn, clock: %Clock{id: id} = clock} do
    #   conn = put(conn, ~p"/api/clocks/#{clock}", clock: @update_attrs)
    #   assert %{"id" => ^id} = json_response(conn, 200)["data"]

    #   conn =
    #     conn
    #     |> put_req_header("authorization", "Bearer #{@token}")
    #     |> get(conn, ~p"/api/clocks/#{id}")

    #   assert %{
    #            "id" => ^id,
    #            "end" => "2023-10-25T15:13:00Z",
    #            "start" => "2023-10-25T15:13:00Z",
    #            "status" => false
    #          } = json_response(conn, 200)["data"]
    # end

    # test "renders errors when data is invalid", %{conn: conn, clock: clock} do
    #   conn =
    #     conn
    #     |> put_req_header("authorization", "Bearer #{@token}")
    #     |> put(
    #       ~p"/api/clocks/#{clock}",
    #       Map.put(Map.put(clock, "_method", "put"), "clock", @invalid_attrs)
    #     )

    #   assert json_response(conn, 422)["errors"] != %{}
    # end
  # end

  # describe "delete clock" do
  #   setup [:create_clock]

  #   test "deletes chosen clock", %{conn: conn, clock: clock} do
  #     conn =
  #       conn
  #       |> put_req_header("authorization", "Bearer #{@token}")
  #       |> delete(conn, ~p"/api/clocks/#{clock}")

  #     assert response(conn, 204)

  #     assert_error_sent(404, fn ->
  #       get(conn, ~p"/api/clocks/#{clock}")
  #     end)
  #   end
  # end

  # defp create_clock(_) do
  #   clock = clock_fixture()
  #   %{clock: clock}
  # end
end
