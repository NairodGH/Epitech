defmodule Api.Repo.Migrations.AlterUsersAddRelationTeams do
  use Ecto.Migration

  def change do
    alter table("users") do
      add :team, references(:teams, on_delete: :nothing, type: :binary_id)
    end

    create index(:users, [:team])
  end
end
