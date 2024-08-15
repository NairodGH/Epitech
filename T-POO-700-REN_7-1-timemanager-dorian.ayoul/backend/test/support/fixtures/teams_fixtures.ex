defmodule Api.TeamsFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Teams` context.
  """

  @doc """
  Generate a team.
  """
  def team_fixture(attrs \\ %{}) do
    {:ok, team} =
      attrs
      |> Enum.into(%{
        name: "la super team",
        manager: "e0acf741-3c2c-449b-8a49-8b121a5a63e8"
      })
      |> Api.Teams.create_team()

    team
  end
end
