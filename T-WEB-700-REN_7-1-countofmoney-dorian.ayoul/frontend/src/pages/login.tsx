import Container from "@/components/templates/Container";
import { LoginDto } from "@/store/api/backendApi/endpoints/v1";
import { Button, Input } from "@material-tailwind/react";
import { signIn } from "next-auth/react";
import Image from "next/image";
import Link from "next/link";
import { useForm } from "react-hook-form";
import { yupResolver } from "@hookform/resolvers/yup";
import * as yup from "yup";
import { useState } from "react";
import { toast } from "react-toastify";
import { useRouter } from "next/router";

const schema = yup
  .object({
    email: yup.string().email().required(),
    password: yup.string().min(8).required(),
  })
  .required();

export default function Login() {
  const {
    register,
    handleSubmit,
    formState: { errors },
  } = useForm<LoginDto>({ resolver: yupResolver(schema) });
  const router = useRouter();
  const [isLoading, setIsLoading] = useState(false);

  async function onSubmit(data: LoginDto) {
    setIsLoading(true);
    const res = await signIn("credentials", {
      ...data,
      redirect: false,
    });
    setIsLoading(false);

    if (!res?.ok) {
      toast.error(res?.error);
    } else {
      router.push("/");
    }
  }

  function handleGoogleLogin() {
    signIn("google", { callbackUrl: "/" });
  }

  return (
    <div className="w-full h-screen flex flex-row justify-center items-center">
      <div className="w-full flex flex-col justify-center items-center">
        <Container className="max-w-[30rem] w-full">
          <div className="flex flex-col items-center gap-10">
            <p className="text-3xl font-extrabold">Login</p>

            <div className="w-full flex flex-col items-center gap-8">
              <div className="w-full flex flex-col items-center gap-6">
                <form onSubmit={handleSubmit(onSubmit)} className="w-full">
                  <div className="w-full flex flex-col items-center gap-6">
                    <div className="w-full flex flex-col gap-4">
                      <div className="flex flex-col gap-1">
                        <Input
                          type="text"
                          label="Email"
                          error={!!errors.email}
                          {...register("email")}
                        />
                        {errors.email && (
                          <p className="text-red-500 text-xs">
                            {errors.email.message}
                          </p>
                        )}
                      </div>
                      <div className="flex flex-col gap-1">
                        <Input
                          type="password"
                          label="Password"
                          error={!!errors.password}
                          {...register("password")}
                        />
                        {errors.password && (
                          <p className="text-red-500 text-xs">
                            {errors.password.message}
                          </p>
                        )}
                      </div>
                    </div>

                    <Button type="submit" fullWidth disabled={isLoading}>
                      Login
                    </Button>
                  </div>
                </form>

                <div className="w-fit flex flex-row text-sm text-gray-600">
                  <p>Don&#39;t have an account?&nbsp;</p>
                  <Link
                    href="/register"
                    className="underline text-blue-gray-700"
                  >
                    Register
                  </Link>
                </div>
              </div>

              <div className="w-full flex flex-row items-center gap-5">
                <div className="w-full h-px bg-gray-500" />
                <p className="w-fit shrink-0 text-gray-700">or sign in with</p>
                <div className="w-full h-px bg-gray-500" />
              </div>

              <div className="w-full">
                <Button
                  fullWidth
                  size="sm"
                  variant="outlined"
                  color="blue-gray"
                  className="flex items-center gap-3"
                  onClick={handleGoogleLogin}
                >
                  <div className="w-full flex justify-center items-center gap-5">
                    <Image
                      src="/google-logo.svg"
                      alt="google"
                      width={30}
                      height={30}
                    />
                    <p className="leading-none text-sm">Continue with Google</p>
                  </div>
                </Button>
              </div>
            </div>
          </div>
        </Container>
      </div>
    </div>
  );
}
