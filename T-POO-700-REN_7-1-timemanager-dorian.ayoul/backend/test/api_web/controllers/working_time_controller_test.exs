defmodule ApiWeb.WorkingTimeControllerTest do
  use ApiWeb.ConnCase

  @invalid_attrs %{start: nil, end: nil, user: nil}
  @token "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJhdWQiOiJKb2tlbiIsImV4cCI6MzY5OTUzMzgzOSwiaWF0IjoxNjk5NTI2NjM5LCJpc3MiOiJKb2tlbiIsImp0aSI6IjJ1YXVzdWI4dHJqaTNwYjhzODAwMDAwMyIsIm5iZiI6MTY5OTUyNjYzOSwicm9sZSI6InVzZXIiLCJ1c2VyX2lkIjoiMDM5YjZiMWYtZjJmNy00MWE3LThjYjMtYjY5NDdiZTAxZWZkIn0.S3XWc2BB3BXFK4flPcgJzqA41gyMStJagiBjrBtQ2TU"

  setup %{conn: conn} do
    {:ok, conn: put_req_header(conn, "accept", "application/json")}
  end

  describe "index" do
    test "lists all workingtimes", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> get(~p"/api/working_times")

      assert json_response(conn, 200)["data"] == []
    end
  end

  describe "create working_time" do
    # test "renders working_time when data is valid", %{conn: conn} do
    #   conn =
    #     conn
    #     |> put_req_header("authorization", "Bearer #{@token}")
    #     |> post(~p"/api/working_times", working_time: @create_attrs)

    #   assert %{"id" => id} = json_response(conn, 201)["data"]

    #   conn = get(conn, ~p"/api/working_times/#{id}")

    #   assert %{
    #            "id" => ^id,
    #            "end" => "2023-10-24T15:13:00Z",
    #            "start" => "2023-10-24T15:13:00Z"
    #          } = json_response(conn, 200)["data"]
    # end

    test "renders errors when data is invalid", %{conn: conn} do
      conn =
        conn
        |> put_req_header("authorization", "Bearer #{@token}")
        |> post(~p"/api/working_times", working_time: @invalid_attrs)

      assert text_response(conn, 409) != %{}
    end
  end

  # describe "update working_time" do
  #   setup [:create_working_time]

  #   test "renders working_time when data is valid", %{
  #     conn: conn,
  #     working_time: %WorkingTime{id: id} = working_time
  #   } do
  #     conn = put(conn, ~p"/api/working_times/#{working_time}", working_time: @update_attrs)
  #     assert %{"id" => ^id} = json_response(conn, 200)["data"]

  #     conn = get(conn, ~p"/api/working_times/#{id}")

  #     assert %{
  #              "id" => ^id,
  #              "end" => "2023-10-25T15:13:00Z",
  #              "start" => "2023-10-25T15:13:00Z"
  #            } = json_response(conn, 200)["data"]
  #   end

  #   test "renders errors when data is invalid", %{conn: conn, working_time: working_time} do
  #     conn = put(conn, ~p"/api/working_times/#{working_time}", working_time: @invalid_attrs)
  #     assert json_response(conn, 422)["errors"] != %{}
  #   end
  # end

  # describe "delete working_time" do
  #   setup [:create_working_time]

  #   test "deletes chosen working_time", %{conn: conn, working_time: working_time} do
  #     conn = delete(conn, ~p"/api/working_times/#{working_time}")
  #     assert response(conn, 204)

  #     assert_error_sent(404, fn ->
  #       get(conn, ~p"/api/working_times/#{working_time}")
  #     end)
  #   end
  # end

  # defp create_working_time(_) do
    # working_time = working_time_fixture()
    # %{working_time: working_time}
  # end
end
