import React, { ReactNode } from "react";
import SideBar from "../molecules/SideBar";
import useTabs from "@/hooks/useTabs";
import { useSession } from "next-auth/react";
import { Avatar, Button } from "@material-tailwind/react";
import Link from "next/link";

type PageWrapperProps = {
  children: ReactNode;
};

function ActionButton() {
  const { data, status } = useSession();

  if (status === "authenticated") {
    return (
      <Avatar
        src={data?.user?.image ?? "/avatar-empty.png"}
        size="md"
        alt="avatar"
      />
    );
  } else {
    return (
      <Link href="/login">
        <Button color="gray" type="button">
          Sign in
        </Button>
      </Link>
    );
  }
}

export default function PageWrapper(props: PageWrapperProps) {
  const { getActualTab } = useTabs();
  const actualTab = getActualTab();

  return (
    <div className="w-full min-h-screen flex flex-row">
      <SideBar />

      <div className="w-full max-h-screen flex flex-col">
        <div className="flex flex-row justify-between items-center bg-white p-5 shadow">
          <h1 className="text-3xl font-extrabold">{actualTab?.name}</h1>
          <ActionButton />
        </div>
        <div className="w-full p-5 overflow-scroll">{props.children}</div>
      </div>
    </div>
  );
}
