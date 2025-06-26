import { FeedItemDetailsDto } from "@/store/api/backendApi/endpoints/v1";
import Image from "next/image";

type ArticleProps = FeedItemDetailsDto;

function formatDate(date: string) {
  const dateObj = new Date(date);
  return dateObj.toLocaleDateString();
}

export default function Article(props: ArticleProps) {
  const { title, content, imageUrl, pubDate, link } = props;

  return (
    <div className="flex flex-col gap-y-10">
      <h1 className="text-2xl font-extrabold">{title}</h1>

      <div className="flex flex-col lg:flex-row gap-12">
        {/* Affichage du contenu HTML */}
        <div
          className="text-start"
          dangerouslySetInnerHTML={{ __html: content }}
        />

        {/* Affichage de l'image */}
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
        <p>Publié le: {formatDate(pubDate)}</p>
      </div>
    </div>
  );
}