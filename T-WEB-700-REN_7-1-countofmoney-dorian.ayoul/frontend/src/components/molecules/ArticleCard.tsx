import {
  Card,
  CardHeader,
  CardBody,
  Typography,
  CardFooter,
  Button,
} from "@material-tailwind/react";
import Image from "next/image";
import Link from "next/link";

type ArticleProps = {
  id: string;
  title: string;
  image?: string;
};

export default function ArticleCard(props: ArticleProps) {
  const { id, title, image } = props;

  return (
    <Card className="w-full">
      {image && (
        <CardHeader color="gray" floated={false} className="h-80">
          <Image
            className="min-w-full min-h-full"
            loader={({ src }) => src}
            src={image}
            alt="card-image"
            width={400}
            height={400}
          />
        </CardHeader>
      )}
      <CardBody>
        <Typography variant="h5" color="blue-gray" className="mb-2">
          {title}
        </Typography>
      </CardBody>
      <CardFooter className="pt-0">
        <Link href={`/articles/${id}`}>
          <Button>Read More</Button>
        </Link>
      </CardFooter>
    </Card>
  );
}
