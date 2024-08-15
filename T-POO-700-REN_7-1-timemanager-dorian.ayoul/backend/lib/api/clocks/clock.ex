defmodule Api.Clocks.Clock do
  use Ecto.Schema
  import Ecto.Changeset

  @primary_key {:id, :binary_id, autogenerate: true}
  @foreign_key_type :binary_id
  schema "clocks" do
    field :start, :utc_datetime
    field :status, :boolean, default: false
    field :end, :utc_datetime
    field :user, :binary_id

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(clock, attrs) do
    clock
    |> cast(attrs, [:id, :start, :end, :status, :user])
    |> validate_required([:user])
  end
end
