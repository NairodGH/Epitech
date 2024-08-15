defmodule Api.Clocks do
  @moduledoc """
  The Clocks context.
  """

  import Ecto.Query, warn: false
  alias Api.Repo

  alias Api.Clocks.Clock

  @doc """
  Returns the list of clocks.

  ## Examples

      iex> list_clocks()
      [%Clock{}, ...]

  """
  def list_clocks do
    Repo.all(Clock)
  end

  @doc """
  Gets a single clock.

  Raises `Ecto.NoResultsError` if the Clock does not exist.

  ## Examples

      iex> get_clock!(123)
      %Clock{}

      iex> get_clock!(456)
      ** (Ecto.NoResultsError)

  """
  def get_clock!(id), do: Repo.get!(Clock, id)

  @doc """
  Gets user clocks.

  Raises `Ecto.NoResultsError` if the Clock does not exist.

  ## Examples

      iex> get_user_clocks!(123)
      %Clock{}

      iex> get_user_clocks!(456)
      ** (Ecto.NoResultsError)

  """
  def get_user_clocks!(id), do: Repo.all(from c in Clock, where: c.user == ^id)

  @doc """
  Gets a single clock.

  Raises `Ecto.NoResultsError` if the Clock does not exist.

  ## Examples

      iex> get_not_finished_clock!(123)
      %Clock{}

      iex> get_not_finished_clock!(456)
      ** (Ecto.NoResultsError)

  """
  def get_not_finished_clock!(user_id), do: Repo.one(from c in Clock, where: c.user == ^user_id and c.status == false)

  @doc """
  Creates a clock.

  ## Examples

      iex> create_clock(%{field: value})
      {:ok, %Clock{}}

      iex> create_clock(%{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def create_clock(attrs \\ %{}) do
    %Clock{}
    |> Clock.changeset(attrs)
    |> Repo.insert()
  end

  @doc """
  Updates a clock.

  ## Examples

      iex> update_clock(clock, %{field: new_value})
      {:ok, %Clock{}}

      iex> update_clock(clock, %{field: bad_value})
      {:error, %Ecto.Changeset{}}

  """
  def update_clock(%Clock{} = clock, attrs) do
    clock
    |> Clock.changeset(attrs)
    |> Repo.update()
  end

  @doc """
  Deletes a clock.

  ## Examples

      iex> delete_clock(clock)
      {:ok, %Clock{}}

      iex> delete_clock(clock)
      {:error, %Ecto.Changeset{}}

  """
  def delete_clock(%Clock{} = clock) do
    Repo.delete(clock)
  end

  @doc """
  Deletes a user clocks.

  ## Examples

      iex> delete_user_clocks(user_id)
      {:ok, %Clock{}}

      iex> delete_user_clocks(user_id)
      {:error, %Ecto.Changeset{}}

  """
  def delete_user_clocks(user_id), do: Repo.delete_all(from c in Clock, where: c.user == ^user_id)

  @doc """
  Returns an `%Ecto.Changeset{}` for tracking clock changes.

  ## Examples

      iex> change_clock(clock)
      %Ecto.Changeset{data: %Clock{}}

  """
  def change_clock(%Clock{} = clock, attrs \\ %{}) do
    Clock.changeset(clock, attrs)
  end
end
