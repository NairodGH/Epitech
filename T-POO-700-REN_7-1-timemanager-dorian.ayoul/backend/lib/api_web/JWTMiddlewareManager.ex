defmodule ApiWeb.JWTMiddlewareManager do
  @behaviour Plug

  def init(_opts), do: %{}

  def call(conn, _opts) do
    case validate_jwt(conn) do
      {:ok, opts} ->
        if opts["role"] == "admin" || opts["role"] == "manager" do
          conn
        else
          conn
          |> Plug.Conn.put_status(:forbidden)
          |> Phoenix.Controller.text("Access denied. Insufficient permissions.")
          |> Plug.Conn.halt()
        end

      {:error, reason} ->
        conn
        |> Plug.Conn.put_status(:unauthorized)
        |> Phoenix.Controller.text(reason)
        |> Plug.Conn.halt()
    end
  end

  defp validate_jwt(conn) do
    case get_token(conn) do
      {:ok, token} ->
        case Api.Token.verify_and_validate(token, Api.Token.get_signer()) do
          {:ok, claims} ->
            {:ok, claims}

          {:error, _reason} ->
            {:error, "Invalid or expired token"}
        end

      {:error, reason} ->
        {:error, reason}
    end
  end

  defp get_token(conn) do
    case Plug.Conn.get_req_header(conn, "authorization") do
      ["Bearer " <> token | _] ->
        {:ok, token}

      _ ->
        {:error, "Token not provided or in the correct format"}
    end
  end
end
