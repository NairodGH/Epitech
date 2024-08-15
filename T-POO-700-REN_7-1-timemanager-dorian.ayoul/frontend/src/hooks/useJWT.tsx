import { useEffect, useState } from "react";
import { jwtDecode } from "jwt-decode";

export type UseJWTReturn = {
  token: string | null;
  id: string | null;
  role: string | null;

  storeToken: (token: string) => void;
  removeToken: () => void;
  isAuthenticated: () => boolean;
};

export function useJWT(): UseJWTReturn {
  const [token, setToken] = useState<string | null>(null);
  const [id, setId] = useState<string | null>(null);
  const [role, setRole] = useState<string | null>(null);
  const [exp, setExp] = useState<number | null>(null);

  function storeToken(token: string) {
    const {
      user_id,
      role: user_role,
      exp: exp_date,
    } = jwtDecode(token) as { user_id: string; role: string; exp: number };

    setToken(token);
    setId(user_id);
    setRole(user_role);
    setExp(exp_date);

    localStorage.setItem("token", token);
  }

  function removeToken() {
    setToken(null);
    setId(null);
    setRole(null);
    setExp(null);

    localStorage.removeItem("token");
  }

  function isAuthenticated() {
    if (!token) return false;
    if (!exp) return false;
    if (exp < Date.now() / 1000) return false;

    return true;
  }

  useEffect(() => {
    const token = localStorage.getItem("token");
    if (token) {
      storeToken(token);
    }
  }, []);

  return { token, id, role, storeToken, removeToken, isAuthenticated };
}
