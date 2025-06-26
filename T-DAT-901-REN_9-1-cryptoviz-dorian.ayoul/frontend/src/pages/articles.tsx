import { Pagination } from "@/components/atoms/Pagination";
import ArticleCard from "@/components/molecules/ArticleCard";
import Container from "@/components/templates/Container";
import PageWrapper from "@/components/templates/Wrapper";
import {
  useFeedsControllerGetFeedsCountQuery,
  useFeedsControllerGetNFeedsWithOffsetQuery,
} from "@/store/api/backendApi/endpoints/v1";
import { useState } from "react";

export default function Articles() {
  const itemPerPage = 9;
  const [page, setPage] = useState(1);
  const { data: articlesNumber } = useFeedsControllerGetFeedsCountQuery();
  const { data: articles } = useFeedsControllerGetNFeedsWithOffsetQuery(
    { n: itemPerPage, offset: (page - 1) * itemPerPage },
    { refetchOnMountOrArgChange: true }
  );

  function onPageChange(page: number) {
    console.log(page);
    setPage(page);
  }

  return (
    <PageWrapper>
      <div className="h-full flex flex-col justify-between">
        <div className="grid grid-cols-3 gap-4">
          {articles?.map((article) => (
            <ArticleCard
              key={article.id}
              id={article.id}
              title={article.title}
              image={article.imageUrl}
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

        <div className="mx-auto p-10">
          <Pagination
            pageNumber={articlesNumber ? Math.ceil(articlesNumber / itemPerPage) : 4}
            onPageChange={onPageChange}
          />
        </div>
      </div>
    </PageWrapper>
  );
}
