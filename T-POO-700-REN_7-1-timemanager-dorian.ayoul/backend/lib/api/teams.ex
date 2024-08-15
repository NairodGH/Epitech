defmodule Api.Teams do
  @moduledoc """
  The Teams context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Teams.Team
  alias Api.Users.User

  @doc """
  Returns the list of teams.

  ## Examples

      iex> list_teams()
      [%Team{}, ...]

  """
  def list_teams do
    Repo.all(Team)
  end

  @doc """
  Gets a single team.

  Raises `Ecto.NoResultsError` if the Team does not exist.

  ## Examples

      iex> get_team!(fde0646f-a4b0-476a-baf5-be72cb8c7c64)
      %Team{}

      iex> get_team!(456)
      ** (Ecto.NoResultsError)

  """
  def get_team!(id), do: Repo.get!(Team, id)

  @doc """
  Gets a all users from a team.

  Raises `Ecto.NoResultsError` if the Team does not exist.

  ## Examples

      iex> get_users_from_team!(fde0646f-a4b0-476a-baf5-be72cb8c7c64)
      %Team{}

      iex> get_users_from_team!(456)
      ** (Ecto.NoResultsError)

  """
  def get_users_from_team!(id), do: Repo.all(from(u in User, where: u.team == ^id))

  @doc """
  Gets all clocks from a team.

  Raises `Ecto.NoResultsError` if the Team does not exist.

  ## Examples

      iex> get_clocks_from_team!(fde0646f-a4b0-476a-baf5-be72cb8c7c64)
      %Team{}

      iex> get_clocks_from_team!(456)
      ** (Ecto.NoResultsError)

  """
  def get_clocks_from_team!(id) do
    users = get_users_from_team!(id)
    clocks = Enum.map(users, fn user -> Api.Clocks.get_user_clocks!(user.id) end)
    List.flatten(clocks)
  end

  @doc """
  Gets a all teams from a user.

  Raises `Ecto.NoResultsError` if the User does not exist.

  ## Examples

      iex> get_teams_from_user!(fde0646f-a4b0-476a-baf5-be72cb8c7c64)
      %Team{}

      iex> get_teams_from_user!(456)
      ** (Ecto.NoResultsError)

  """
  def get_teams_from_user!(id), do: Repo.all(from(t in Team, where: t.manager == ^id))

  @doc """
  Creates a team.

  ## Examples

      iex> create_team(%{field: value})
      {:ok, %Team{}}

      iex> create_team(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_team(attrs \\ %{}) do
    %Team{}
    |> Team.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a team.

  ## Examples

      iex> update_team(team, %{field: new_value})
      {:ok, %Team{}}

      iex> update_team(team, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_team(%Team{} = team, attrs) do
    team
    |> Team.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a team and unlink all users.

  ## Examples

      iex> delete_team(team)
      {:ok, %Team{}}

      iex> delete_team(team)
      {:error, %Ecto.Changeset{}}

  """
  def delete_team(%Team{} = team) do
    Repo.update_all(from(u in User, where: u.team == ^team.id), set: [team: nil])
    Repo.delete(team)
  end

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking team changes.

  ## Examples

      iex> change_team(team)
      %Ecto.Changeset{data: %Team{}}

  """
  def change_team(%Team{} = team, attrs \\ %{}) do
    Team.changeset(team, attrs)
  end
end
