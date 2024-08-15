import { GetFeedItemDto } from "@/store/api/backendApi/endpoints/v1";
import Image from "next/image";

type ArticleFullProps = GetFeedItemDto;

function formatDate(date: string) {
  const dateObj = new Date(date);

  return dateObj.toLocaleDateString();
}

export default function ArticleFull(props: ArticleFullProps) {
  const { title, content, imageUrl, createdAt, link } = props;

  return (
    <div className="flex flex-col gap-y-10">
      <h1 className="text-4xl font-extrabold">{title}</h1>

      <div className="flex flex-col lg:flex-row gap-12">
        <div
          className="text-justify"
          dangerouslySetInnerHTML={{ __html: content }}
        />

        {imageUrl && (
          <Image
            className="rounded-xl h-fit"
            loader={({ src }) => src}
            src={imageUrl}
            alt="article-image"
            width={400}
            height={400}
          />
        )}
      </div>

      <div className="flex flex-row justify-between">
        <p>{link && `Source: ${link}`}</p>

        <p>Published: {formatDate(createdAt)}</p>
      </div>
    </div>
  );
}
