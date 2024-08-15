"use client";

import LoginForm from "@/components/LoginForm";
import Link from "next/link";

export default function Login() {
  return (
    <div className="w-screen h-screen bg-[url('/assets/background.jpg')] bg-cover flex items-center justify-center">
      <div className="flex flex-col items-center w-auto p-10 rounded-xl bg-black bg-opacity-50">
        <LoginForm />

        <p>
          Don&#39;t have an account yet ?{" "}
          <Link href="/register" className="text-[#1DB2F5] underline">
            Register here.
          </Link>
        </p>
      </div>
    </div>
  );
}
