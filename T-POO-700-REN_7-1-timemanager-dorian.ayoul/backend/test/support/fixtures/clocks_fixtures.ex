defmodule Api.ClocksFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.Clocks` context.
  """

  @doc """
  Generate a clock.
  """
  def clock_fixture(attrs \\ %{}) do
    {:ok, clock} =
      attrs
      |> Enum.into(%{
        end: ~U[2023-10-24 15:13:00Z],
        start: ~U[2023-10-24 15:13:00Z],
        status: true,
        user: "e0acf741-3c2c-449b-8a49-8b121a5a63e8"
      })
      |> Api.Clocks.create_clock()

    clock
  end
end
