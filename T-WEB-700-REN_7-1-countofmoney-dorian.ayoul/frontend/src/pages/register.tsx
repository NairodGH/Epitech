import Container from "@/components/templates/Container";
import {
  LoginDto,
  useUsersControllerRegisterMutation,
} from "@/store/api/backendApi/endpoints/v1";
import { yupResolver } from "@hookform/resolvers/yup";
import { Button, Input } from "@material-tailwind/react";
import { signIn } from "next-auth/react";
import Image from "next/image";
import Link from "next/link";
import { useRouter } from "next/router";
import { useState } from "react";
import { useForm } from "react-hook-form";
import { toast } from "react-toastify";
import * as yup from "yup";

type RegisterDto = LoginDto & {
  confirmPassword: string;
};

const schema = yup
  .object({
    email: yup.string().email().required(),
    password: yup.string().min(8).required(),
    confirmPassword: yup
      .string()
      .oneOf([yup.ref("password")], "Passwords must match")
      .required(),
  })
  .required();

export default function Register() {
  const {
    register,
    handleSubmit,
    formState: { errors },
  } = useForm<RegisterDto>({ resolver: yupResolver(schema) });

  const router = useRouter();
  const [registerMutation] = useUsersControllerRegisterMutation();
  const [isLoading, setIsLoading] = useState(false);

  async function onSubmit(data: RegisterDto) {
    setIsLoading(true);
    const taostId = toast.loading("Registering...", { autoClose: false });

    try {
      await registerMutation({
        loginDto: { email: data.email, password: data.password },
      }).unwrap();
      const res = await signIn("credentials", {
        ...data,
        redirect: false,
      });

      if (!res?.ok) {
        new Error("Regitsration success but login failed");
      } else {
        router.push("/");
        toast.update(taostId, {
          render: "Register success",
          type: "success",
          autoClose: 3000,
          isLoading: false,
        });
      }
    } catch (error) {
      toast.update(taostId, {
        render: "Register failed",
        type: "error",
        autoClose: 3000,
        isLoading: false,
      });
    }

    setIsLoading(false);
  }

  function handleGoogleLogin() {
    signIn("google", { callbackUrl: "/" });
  }

  return (
    <div className="w-full h-screen flex flex-row justify-center items-center">
      <div className="w-full flex flex-col justify-center items-center">
        <Container className="max-w-[30rem] w-full">
          <div className="flex flex-col items-center gap-10">
            <p className="text-3xl font-extrabold">Register</p>

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
                      <div className="flex flex-col gap-1">
                        <Input
                          type="password"
                          label="Confirm Password"
                          error={!!errors.confirmPassword}
                          {...register("confirmPassword")}
                        />
                        {errors.confirmPassword && (
                          <p className="text-red-500 text-xs">
                            {errors.confirmPassword.message}
                          </p>
                        )}
                      </div>
                    </div>

                    <Button type="submit" fullWidth disabled={isLoading}>
                      Register
                    </Button>
                  </div>
                </form>

                <div className="w-fit flex flex-row text-sm text-gray-600">
                  <p>Already have an account?&nbsp;</p>
                  <Link href="/login" className="underline text-blue-gray-700">
                    Login
                  </Link>
                </div>
              </div>

              <div className="w-full flex flex-row items-center gap-5">
                <div className="w-full h-px bg-gray-500" />
                <p className="w-fit shrink-0 text-gray-700">or sign up with</p>
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
