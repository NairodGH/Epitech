import { FeedItemSummaryDto } from "@/store/api/backendApi/endpoints/v1";
import {
  Button,
  Card,
  CardBody,
  CardFooter,
  Chip,
  Menu,
  MenuHandler,
  MenuList,
  Typography,
} from "@material-tailwind/react";
import { useState } from "react";
import Link from "next/link";
import { GrArticle } from "react-icons/gr";

type ArticlePreviewProps = {
  article: FeedItemSummaryDto;
};

export default function ArticlePreview(props: ArticlePreviewProps) {
  const {
    article: { id, title },
  } = props;
  const [open, setOpen] = useState(false);

  return (
    <Menu open={open} handler={setOpen} allowHover>
      <MenuHandler>
        <Chip className="w-fit" value={<GrArticle size="20px" />} />
      </MenuHandler>

      <MenuList className="max-w-lg">
        <div className="border-none">
          <CardBody>
            <Typography variant="h5" color="blue-gray">
              {title}
            </Typography>
          </CardBody>
          <CardFooter className="pt-0">
            <Link href={`/articles/${id}`}>
              <Button>Read More</Button>
            </Link>
          </CardFooter>
        </div>
      </MenuList>
    </Menu>
  );
}
