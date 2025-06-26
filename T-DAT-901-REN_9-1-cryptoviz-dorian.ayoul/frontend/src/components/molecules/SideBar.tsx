import useTabs from "@/hooks/useTabs";
import Tab from "@/components/atoms/Tab";
import Image from "next/image";
import Link from "next/link";

export default function SideBar() {
  const { tabs } = useTabs();

  return (
    <div className="max-h-screen flex flex-col justify-between items-center bg-charcoal text-white p-5">
      <div className="w-full flex flex-col items-center gap-10">
        <Link href="/">
          <Image src="/com-logo.svg" alt="logo" width={150} height={150} priority />
        </Link>

        <div className="w-full flex flex-col items-center">
          {tabs.map((tab) => (
            <Tab key={tab.href} {...tab} />
          ))}
        </div>
      </div>
    </div>
  );
}
