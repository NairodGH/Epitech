import ArticleCard from "@/components/molecules/ArticleCard";
import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import { useFeedControllerGetItemsQuery } from "@/store/api/backendApi/endpoints/v1";

export default function Articles() {
  const { data: articles } = useFeedControllerGetItemsQuery(undefined, {
    refetchOnMountOrArgChange: true,
  });

  return (
    <PageWrapper>
      <div className="grid grid-cols-3 gap-4">
        {articles?.map((article) => (
          <ArticleCard
            key={article.id}
            id={article.id}
            title={article.title}
            image={article.image}
          />
        ))}
        {!articles?.length && (
          <Container className="col-span-3">
            <div className="flex flex-row justify-center p-10">
              <>No elements corresponding to your keywords</>
            </div>
          </Container>
        )}
      </div>
    </PageWrapper>
  );
}
