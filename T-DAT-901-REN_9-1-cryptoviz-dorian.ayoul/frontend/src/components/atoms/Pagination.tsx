import React from "react";
import { Button, IconButton } from "@material-tailwind/react";
import { HiArrowLeft, HiArrowRight } from "react-icons/hi";
import { useRouter } from "next/router";

type PaginationProps = {
  pageNumber: number;
  onPageChange: (page: number) => void;
};

export function Pagination(props: PaginationProps) {
  const { pageNumber, onPageChange } = props;
  const router = useRouter();
  const active = Number(router.query.page) || 1;

  function changePage(page: number) {
    onPageChange(page);

    router.push({
      pathname: router.pathname,
      query: { ...router.query, page },
    });
  }

  function getItemProps(index: number) {
    return {
      variant: active === index ? "filled" : "text",
      color: "gray",
      onClick: () => changePage(index),
    } as any;
  }

  function next() {
    changePage(active + 1);
  }

  function prev() {
    changePage(active - 1);
  }

  return (
    <div className="flex items-center gap-4">
      <Button variant="text" className="flex items-center gap-2" onClick={prev} disabled={active === 1}>
        <HiArrowLeft strokeWidth={2} className="h-4 w-4" /> Previous
      </Button>
      <div className="flex items-center gap-2">
        {Array.from({ length: pageNumber }, (_, i) => (
          <IconButton key={i} {...getItemProps(i + 1)}>
            {i + 1}
          </IconButton>
        ))}
      </div>
      <Button variant="text" className="flex items-center gap-2" onClick={next} disabled={active === pageNumber}>
        Next
        <HiArrowRight strokeWidth={2} className="h-4 w-4" />
      </Button>
    </div>
  );
}
