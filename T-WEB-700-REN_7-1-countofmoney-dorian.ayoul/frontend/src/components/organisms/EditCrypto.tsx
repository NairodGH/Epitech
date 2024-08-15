import {
  CryptoDto,
  UpdateCryptoDto,
  useCryptosControllerGetCryptoByIdQuery,
  useCryptosControllerUpdateCryptoMutation,
} from "@/store/api/backendApi/endpoints/v1";
import { yupResolver } from "@hookform/resolvers/yup";
import { Avatar, Button, Input } from "@material-tailwind/react";
import { useEffect } from "react";
import { useForm } from "react-hook-form";
import * as yup from "yup";

type EditCryptoProps = {
  cryptoId?: string;
  handleOpen: () => void;
};

type FormDto = {
  imageUrl: string;
};

const schema = yup
  .object({
    imageUrl: yup.string().required(),
  })
  .required();

export default function EditCrypto(props: EditCryptoProps) {
  const { cryptoId, handleOpen } = props;
  const {
    register,
    handleSubmit,
    formState: { errors },
    setValue,
  } = useForm<FormDto>({
    resolver: yupResolver(schema),
  });

  const { data: crypto, isLoading: isGetCryptoLoading } =
    useCryptosControllerGetCryptoByIdQuery(
      { cmid: cryptoId! },
      { skip: !cryptoId, refetchOnMountOrArgChange: true }
    );

  const [updateCryptoMutation] = useCryptosControllerUpdateCryptoMutation();

  function onSubmit(data: FormDto) {
    updateCryptoMutation({
      cmid: cryptoId!,
      updateCryptoDto: {
        name: crypto?.name!,
        imageUrl: data.imageUrl,
        coinmarketId: crypto?.coinmarketId!,
        default: crypto?.default!,
      },
    });

    handleOpen();
  }

  useEffect(() => {
    if (crypto) {
      setValue("imageUrl", crypto.imageUrl);
    }
  }, [crypto, setValue]);

  return (
    <form className="flex flex-col p-4 gap-5" onSubmit={handleSubmit(onSubmit)}>
      <div className="flex flex-row items-center gap-x-3">
        <Avatar src={crypto?.imageUrl} size="sm" alt="crypto" />
        <h1>{crypto?.name}</h1>
      </div>

      <div className="flex flex-col gap-1">
        <Input
          label="Image URL"
          error={!!errors.imageUrl}
          {...register("imageUrl")}
        />
        {errors.imageUrl && (
          <p className="text-red-500 text-xs">{errors.imageUrl.message}</p>
        )}
      </div>

      <div className="flex flex-row justify-end gap-x-1">
        <Button variant="text" color="red" onClick={handleOpen}>
          Annuler
        </Button>
        <Button
          className="bg-rosy-brown text-black"
          type="submit"
          disabled={isGetCryptoLoading}
        >
          Valider
        </Button>
      </div>
    </form>
  );
}
