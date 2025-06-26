import { useRouter } from "next/router";
import { ReactNode } from "react";
import { FaBuffer, FaNewspaper } from "react-icons/fa6";

export type Tab = {
  icon: ReactNode;
  name: ReactNode;
  href: string;
  isDisplayed: (role: string) => boolean;
};

const tabs: Tab[] = [
  {
    icon: <FaBuffer />,
    name: "Dashboard",
    href: "/dashboard",
    isDisplayed: () => true,
  },
  {
    icon: <FaNewspaper />,
    name: "Articles",
    href: "/articles",
    isDisplayed: () => true,
  },
];

export default function useTabs() {
  const router = useRouter();
  function getActualTab() {
    return tabs.find((tab) => router.pathname.includes(tab.href));
  }

  return { tabs, getActualTab };
}
