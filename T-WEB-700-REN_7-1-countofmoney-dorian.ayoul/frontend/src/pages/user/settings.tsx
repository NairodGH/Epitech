import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import {
  useCryptosControllerGetAvailableCryptosQuery,
  useUsersControllerProfileQuery,
  useUsersControllerUpdateProfileMutation,
} from "@/store/api/backendApi/endpoints/v1";
import { yupResolver } from "@hookform/resolvers/yup";
import { Avatar, Button, Checkbox, Input } from "@material-tailwind/react";
import { useSession } from "next-auth/react";
import { useEffect, useState } from "react";
import { useForm } from "react-hook-form";
import * as yup from "yup";

type FormDto = {
  cryptos: string[];
  keywords?: string;
};

const schema = yup
  .object({
    cryptos: yup.array().of(yup.string().required()).required(),
    keywords: yup.string().optional(),
  })
  .required();

export default function Settings() {
  const { register, handleSubmit, setValue } = useForm<FormDto>({
    resolver: yupResolver(schema),
  });

  const { data } = useSession();
  const { data: availableCryptos, isLoading: isGetCryptosLoading } =
    useCryptosControllerGetAvailableCryptosQuery(undefined, {
      refetchOnMountOrArgChange: true,
    });
  const {
    data: userProfile,
    isLoading: isGetUserProfileLoading,
    refetch: refetchUserProfile,
  } = useUsersControllerProfileQuery(undefined, {
    refetchOnMountOrArgChange: true,
  });

  const [updateProfileMutation] = useUsersControllerUpdateProfileMutation();

  const [isLoading, setIsLoading] = useState(false);

  useEffect(() => {
    setIsLoading(isGetCryptosLoading || isGetUserProfileLoading);
  }, [isGetCryptosLoading, isGetUserProfileLoading]);

  useEffect(() => {
    if (!availableCryptos || !userProfile) return;

    const selectedCryptosTemp = userProfile.cryptos.map((userCrypto) => {
      const crypto = availableCryptos.find(
        (crypto) => crypto.id === userCrypto
      );

      return crypto?.id!;
    });

    if (!selectedCryptosTemp) return;
    setValue("cryptos", selectedCryptosTemp);
  }, [availableCryptos, userProfile, setValue]);

  async function onSubmit(data: FormDto) {
    setIsLoading(true);
    await updateProfileMutation({
      updateUserDto: {
        cryptos: data.cryptos,
        keywords: data.keywords ? [data.keywords] : [],
      },
    }).unwrap();
    await refetchUserProfile();
    setIsLoading(false);
  }

  return (
    <PageWrapper>
      <form onSubmit={handleSubmit(onSubmit)}>
        <div className="grid grid-flow-row grid-cols-2 gap-4">
          <Container>
            <div className="flex flex-row justify-between items-center gap-8">
              <Avatar
                src={data?.user?.image ?? "/avatar-empty.png"}
                size="xxl"
                alt="avatar"
              />
              <h1 className="w-full">{data?.user?.email ?? ""}</h1>
            </div>
          </Container>

          <Container>
            <div className="h-full flex flex-col justify-between">
              <Input type="text" label="Keywords" {...register("keywords")} />
              <Button
                className="bg-rosy-brown text-black"
                type="submit"
                disabled={isLoading}
              >
                Update
              </Button>
            </div>
          </Container>

          <Container className="h-full p-5 col-span-2">
            <div className="w-full h-full flex flex-col justify-between">
              <div className="flex flex-row justify-between items-center">
                <h1 className="text-xl font-semibold">Select a crypto</h1>
                <Button
                  className="bg-rosy-brown text-black"
                  type="submit"
                  disabled={isLoading}
                >
                  Update
                </Button>
              </div>
              <ul className="flex flex-col">
                {availableCryptos?.map((crypto) => (
                  <label
                    key={crypto.id}
                    className="hover:bg-tea-rose hover:bg-opacity-20 rounded-lg transition-all cursor-pointer"
                  >
                    <Checkbox
                      className="checked:bg-tea-rose checked:border-transparent"
                      label={crypto.name}
                      value={crypto.id}
                      {...register("cryptos")}
                    />
                  </label>
                ))}
              </ul>
            </div>
          </Container>
        </div>
      </form>
    </PageWrapper>
  );
}
