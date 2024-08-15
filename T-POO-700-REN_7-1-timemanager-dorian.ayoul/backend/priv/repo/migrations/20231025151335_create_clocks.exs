defmodule Api.Repo.Migrations.CreateClocks do
  use Ecto.Migration

  def change do
    create table(:clocks, primary_key: false) do
      add :id, :binary_id, primary_key: true
      add :start, :utc_datetime, null: false
      add :end, :utc_datetime
      add :status, :boolean, default: false, null: false
      add :user, references(:users, on_delete: :nothing, type: :binary_id), null: false

      timestamps(type: :utc_datetime)
    end

    create index(:clocks, [:user])
  end
end
