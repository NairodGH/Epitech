defmodule Api.Repo.Migrations.AddRoleDefaultValue do
  use Ecto.Migration

  def change do
    alter table("users") do
      modify :role, :string, default: "employee", null: false
    end
  end
end
