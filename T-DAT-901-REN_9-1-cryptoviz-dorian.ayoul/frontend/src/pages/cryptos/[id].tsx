import CryptoGraph from "@/components/organisms/CryptoGraph";
import PageWrapper from "@/components/templates/Wrapper";
import { useRouter } from "next/router";

export default function Crypto() {
  const router = useRouter();

  const { id } = router.query;

  return (
    <PageWrapper>
      <CryptoGraph cmid={id as string} />
    </PageWrapper>
  );
}
