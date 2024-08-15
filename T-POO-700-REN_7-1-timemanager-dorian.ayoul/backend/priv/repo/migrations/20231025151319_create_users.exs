defmodule Api.Repo.Migrations.CreateUsers do
  use Ecto.Migration

  def change do
    create table(:users, primary_key: false) do
      add :id, :binary_id, primary_key: true
      add :firstname, :string, null: false
      add :lastname, :string, null: false
      add :role, :string, null: false
      add :email, :string, null: false
      add :password, :string, null: false

      timestamps(type: :utc_datetime)
    end
  end
end
