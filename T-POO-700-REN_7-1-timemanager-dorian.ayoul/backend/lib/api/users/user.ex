defmodule Api.Users.User do
  use Ecto.Schema
  import Ecto.Changeset

  @primary_key {:id, :binary_id, autogenerate: true}
  @foreign_key_type :binary_id
  schema "users" do
    field :password, :string
    field :role, :string, read_after_writes: true, default: "employee"
    field :firstname, :string
    field :lastname, :string
    field :email, :string
    field :team, :binary_id, read_after_writes: true

    timestamps(type: :utc_datetime)
  end

  @doc false
  def changeset(user, attrs) do
    user
    |> cast(attrs, [:firstname, :lastname, :role, :email, :password, :team])
    |> validate_required([:firstname, :lastname, :email, :password])
    |> validate_format(:email, ~r/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/, message: "Please enter a valid email.")
    |> unique_constraint(:email)
    |> hash_password()
  end

  defp hash_password(changeset) do
    case get_change(changeset, :password) do
      nil -> changeset
      password ->
        put_change(changeset, :password, Bcrypt.hash_pwd_salt(password))
    end
  end
end
