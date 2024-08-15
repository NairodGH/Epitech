import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import {
  useConstantControllerUpdateArticlesNumberMutation,
  useCryptosControllerDefaultCryptoMutation,
  useCryptosControllerGetAvailableCryptosQuery,
} from "@/store/api/backendApi/endpoints/v1";
import { FaEdit } from "react-icons/fa";
import { yupResolver } from "@hookform/resolvers/yup";
import { Button, Checkbox, Dialog, Input } from "@material-tailwind/react";
import { useEffect, useState } from "react";
import { useForm } from "react-hook-form";
import * as yup from "yup";
import EditCrypto from "@/components/organisms/EditCrypto";

type FormDto = {
  cmids: string[];
  articlesNumber?: number;
};

const schema = yup
  .object({
    cmids: yup.array().of(yup.string().required()).required(),
    articlesNumber: yup.number().optional(),
  })
  .required();

export default function Defaults() {
  const { register, handleSubmit, setValue } = useForm<FormDto>({
    resolver: yupResolver(schema),
  });

  const { data: cryptos, isLoading: isGetCryptosLoading } =
    useCryptosControllerGetAvailableCryptosQuery();

  const [updateDefaultsMutation] = useCryptosControllerDefaultCryptoMutation();
  const [updateConstantArticlesNumner] =
    useConstantControllerUpdateArticlesNumberMutation();

  const [isLoading, setIsLoading] = useState(false);
  const [isDialogOpen, setIsDialogOpen] = useState(false);
  const [cryptoId, setCryptoId] = useState<string>();

  async function onSubmit(data: FormDto) {
    setIsLoading(true);
    await updateDefaultsMutation({
      defaultCryptoDto: { cmids: data.cmids },
    });
    if (data.articlesNumber) {
      await updateConstantArticlesNumner({
        number: data.articlesNumber,
      });
    }
    setIsLoading(false);
  }

  function handleOpen() {
    setIsDialogOpen(!isDialogOpen);
  }

  function handleEditCrypto(cryptoId: string) {
    setCryptoId(cryptoId);
    setIsDialogOpen(true);
  }

  useEffect(() => {
    setIsLoading(isGetCryptosLoading);
  }, [isGetCryptosLoading]);

  useEffect(() => {
    if (cryptos) {
      const defaultCryptos = cryptos.filter((crypto) => crypto.default);
      const defaultCryptoIds = defaultCryptos.map((crypto) => crypto.id);
      setValue("cmids", defaultCryptoIds);
    }
  }, [cryptos, setValue]);

  return (
    <>
      <PageWrapper>
        <form onSubmit={handleSubmit(onSubmit)}>
          <div className="flex flex-col gap-6">
            <Container>
              <div className="flex flex-col gap-5">
                <Input
                  type="number"
                  label="Number of articles returned by the API"
                  {...register("articlesNumber")}
                />
                <Button
                  className="bg-rosy-brown text-black"
                  type="submit"
                  disabled={isLoading}
                >
                  Update
                </Button>
              </div>
            </Container>

            <Container className="p-5">
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
                  {cryptos?.map((crypto) => (
                    <div
                      key={crypto.id}
                      className="flex flex-row justify-between items-center gap-x-3"
                    >
                      <label className="w-full hover:bg-tea-rose hover:bg-opacity-20 rounded-lg transition-all cursor-pointer">
                        <Checkbox
                          className="checked:bg-tea-rose checked:border-transparent"
                          label={crypto.name}
                          value={crypto.id}
                          {...register("cmids")}
                        />
                      </label>
                      <button
                        className="text-2xl"
                        disabled={isLoading}
                        onClick={() => handleEditCrypto(crypto.id)}
                      >
                        <FaEdit />
                      </button>
                    </div>
                  ))}
                </ul>
              </div>
            </Container>
          </div>
        </form>
      </PageWrapper>
      <Dialog open={isDialogOpen} handler={handleOpen}>
        <EditCrypto cryptoId={cryptoId} handleOpen={handleOpen} />
      </Dialog>
    </>
  );
}
