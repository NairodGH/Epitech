import useTabs from "@/hooks/useTabs";
import Tab from "@/components/atoms/Tab";
import Image from "next/image";
import Link from "next/link";
import { FaArrowRightFromBracket } from "react-icons/fa6";
import { signOut, useSession } from "next-auth/react";

export default function SideBar() {
  const { tabs } = useTabs();
  const { status } = useSession();

  return (
    <div className="max-h-screen flex flex-col justify-between items-center bg-charcoal text-white p-5">
      <div className="w-full flex flex-col items-center gap-10">
        <Link href="/">
          <Image src="/com-logo.svg" alt="logo" width={150} height={150} />
        </Link>

        <div className="w-full flex flex-col items-center">
          {tabs.map((tab) => (
            <Tab key={tab.href} {...tab} />
          ))}
        </div>
      </div>

      {status === "authenticated" && (
        <button
          onClick={() => signOut({ callbackUrl: "/login" })}
          className="w-full flex flex-row justify-start items-center gap-8 p-5 rounded-lg hover:bg-charcoal-400 transition-all"
        >
          <div className="text-2xl">
            <div className="rotate-180">
              <FaArrowRightFromBracket />
            </div>
          </div>
          <p className="text-lg font-light">Logout</p>
        </button>
      )}
    </div>
  );
}
