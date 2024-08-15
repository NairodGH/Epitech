import ArticleFull from "@/components/molecules/ArticleFull";
import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import { useFeedControllerGetItemByIdQuery } from "@/store/api/backendApi/endpoints/v1";
import { Spinner } from "@material-tailwind/react";
import { useRouter } from "next/router";

export default function Article() {
  const router = useRouter();
  const { id } = router.query;

  const { data: article, isLoading } = useFeedControllerGetItemByIdQuery(
    { id: id as string },
    { skip: !id }
  );

  return (
    <PageWrapper>
      <Container>
        {isLoading && (
          <Container>
            <div className="flex flex-row justify-center p-10">
              <Spinner className="h-16 w-16" color="gray" />
            </div>
          </Container>
        )}

        <ArticleFull {...article!} />
      </Container>
    </PageWrapper>
  );
}
