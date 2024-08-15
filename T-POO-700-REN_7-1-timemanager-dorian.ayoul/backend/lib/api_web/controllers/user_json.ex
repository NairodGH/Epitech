defmodule ApiWeb.UserJSON do
  alias Api.Users.User

  @doc """
  Renders a list of users.
  """
  def index(%{users: users}) do
    %{data: for(user <- users, do: data(user))}
  end

  @doc """
  Renders a single user.
  """
  def show(%{user: user}) do
    %{data: data(user)}
  end

  @doc """
  Renders a single user.
  """
  def show_confidential(%{user: user}) do
    %{data: data_confidential(user)}
  end

  defp data(%User{} = user) do
    %{
      id: user.id,
      firstname: user.firstname,
      lastname: user.lastname,
      role: user.role,
      team: user.team
    }
  end

  defp data_confidential(%User{} = user) do
    %{
      id: user.id,
      firstname: user.firstname,
      lastname: user.lastname,
      role: user.role,
      email: user.email,
      team: user.team
    }
  end
end
