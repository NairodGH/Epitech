defmodule Api.WorkingTimesFixtures do
  @moduledoc """
  This module defines test helpers for creating
  entities via the `Api.WorkingTimes` context.
  """

  @doc """
  Generate a working_time.
  """
  def working_time_fixture(attrs \\ %{}) do
    {:ok, working_time} =
      attrs
      |> Enum.into(%{
        end: ~U[2023-10-24 15:13:00Z],
        start: ~U[2023-10-24 15:13:00Z],
        user: "c530fd68-5746-46ea-bc11-b1a7bfb2a797"
      })
      |> Api.WorkingTimes.create_working_time()

    working_time
  end
end
