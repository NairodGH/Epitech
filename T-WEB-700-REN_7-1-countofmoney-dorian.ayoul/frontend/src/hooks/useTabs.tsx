import { useSession } from "next-auth/react";
import { useRouter } from "next/router";
import { ReactNode } from "react";
import { FaBuffer, FaDollarSign, FaGear, FaNewspaper } from "react-icons/fa6";

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
  {
    icon: <FaDollarSign />,
    name: "Defaults",
    href: "/admin/defaults",
    isDisplayed: (role) => role === "ADMIN",
  },
  {
    icon: <FaGear />,
    name: "Settings",
    href: "/user/settings",
    isDisplayed: (role) => role === "USER" || role === "ADMIN",
  },
];

export default function useTabs() {
  const router = useRouter();
  const { data } = useSession();
  const availableTabs = tabs.filter((tab) =>
    tab.isDisplayed((data as any)?.role)
  );

  function getActualTab() {
    return tabs.find((tab) => router.pathname.includes(tab.href));
  }

  return { tabs: availableTabs, getActualTab };
}
