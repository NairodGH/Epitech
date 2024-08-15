defmodule Api.Token do
  use Joken.Config

  @signer Joken.Signer.create("HS256", "your-256-bit-secret")

  def get_signer() do
    @signer
  end
end
