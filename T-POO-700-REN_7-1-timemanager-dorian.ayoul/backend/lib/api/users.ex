defmodule Api.Users do
  @moduledoc """
  The Users context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Users.User

  def login_user(%{"email" => email, "password" => password}) do
    user = Repo.get_by(User, email: email)

    if user do
      case Bcrypt.verify_pass(password, user.password) do
        true -> {:ok, Api.Token.generate_and_sign!(%{"user_id" => user.id, "role" => user.role}, Api.Token.get_signer())}
        false -> {:error, "Invalid email or password"}
      end
    else
      {:error, "Invalid email or password"}
    end
  end

  @doc """
  Returns the list of users.

  ## Examples

      iex> list_users()
      [%User{}, ...]

  """
  def list_users do
    Repo.all(User)
  end

  @doc """
  Finds all users matching the given team id (related to the team table).

  ## Examples

      iex> find_users_by_team(%{team_id: "49bbb3a7-4244-4a51-85ff-3d1bf3998a9e"})
      [%User{}, ...]

  """
  # relation between user and team
  def find_users_by_team!(team_id), do: Repo.all(from(u in User, where: u.team == ^team_id))

  @doc """
  Finds all users matching the given role.

  ## Examples

      iex> find_users_by_role(%{role: "MANAGER"})
      [%User{}, ...]

  """
  def find_users_by_role!(role), do: Repo.all(from(u in User, where: u.role == ^role))

  @doc """
  Finds user matching the given email.

  ## Examples

      iex> find_user_by_email(%{email: "test@mail.com"})
      [%User{}, ...]

  """
  def find_user_by_email!(email), do: Repo.get_by(User, email: email)

  @doc """
  Gets a single user.

  Raises `Ecto.NoResultsError` if the User does not exist.

  ## Examples

      iex> get_user!(49bbb3a7-4244-4a51-85ff-3d1bf3998a9e)
      %User{}

      iex> get_user!(456)
      ** (Ecto.NoResultsError)

  """
  def get_user!(id), do: Repo.get!(User, id)

  @doc """
  Creates a user.

  ## Examples

      iex> create_user(%{field: value})
      {:ok, %User{}}

      iex> create_user(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_user(attrs \\ %{}) do
    %User{}
    |> User.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a user.

  ## Examples

      iex> update_user(user, %{field: new_value})
      {:ok, %User{}}

      iex> update_user(user, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_user(%User{} = user, attrs) do
    user
    |> User.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Updates a user's team.

  ## Examples

      iex> update_team(user, %{team: team})
      {:ok, %User{}}

      iex> update_team(user, %{team: bad_team})
      {:error, %Ecto.Changeset{}}

  """
  def update_team(%User{} = user, team_id) do
    user
    |> User.changeset(%{team: team_id})
    |> Repo.update()
  end

  @doc """
  Deletes a user.

  ## Examples

      iex> delete_user(user)
      {:ok, %User{}}

      iex> delete_user(user)
      {:error, %Ecto.Changeset{}}

  """
  def delete_user(%User{} = user) do
    Repo.delete(user)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking user changes.

  ## Examples

      iex> change_user(user)
      %Ecto.Changeset{data: %User{}}

  """
  def change_user(%User{} = user, attrs \\ %{}) do
    User.changeset(user, attrs)
  end
end
