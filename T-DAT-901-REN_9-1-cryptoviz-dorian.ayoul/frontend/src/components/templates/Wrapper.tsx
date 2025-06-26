import React, { ReactNode } from "react";
import SideBar from "../molecules/SideBar";
import useTabs from "@/hooks/useTabs";
import { useRouter } from "next/router";

type PageWrapperProps = {
  children: ReactNode;
};

export default function PageWrapper(props: PageWrapperProps) {
  const { getActualTab } = useTabs();
  const { pathname } = useRouter();

  function getPageName() {
    const actualTab = getActualTab();

    if (!actualTab) {
      return pathname.split("/")[1];
    }
    return actualTab.name;
  }

  return (
    <div className="w-full min-h-screen flex flex-row">
      <SideBar />

      <div className="w-full max-h-screen flex flex-col">
        <div className="flex flex-row justify-between items-center bg-white p-5 shadow">
          <h1 className="text-3xl font-extrabold capitalize">{getPageName()}</h1>
        </div>
        <div className="w-full h-full p-5 overflow-scroll">{props.children}</div>
      </div>
    </div>
  );
}
