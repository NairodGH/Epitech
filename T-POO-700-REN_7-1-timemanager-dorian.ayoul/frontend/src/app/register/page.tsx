"use client";

import RegisterForm from "@/components/RegisterForm";
import Link from "next/link";

export default function Register() {
  return (
    <div className="w-screen h-screen bg-[url('/assets/background.jpg')] bg-cover flex items-center justify-center">
      <div className="flex flex-col items-center w-auto p-10 rounded-xl bg-black bg-opacity-50">
        <RegisterForm />

        <p>
          Already have an account ?{" "}
          <Link href="/login" className="text-[#1DB2F5] underline">
            Log in here.
          </Link>
        </p>
      </div>
    </div>
  );
}
