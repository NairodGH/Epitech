import { Tab } from "@/hooks/useTabs";
import Link from "next/link";

export default function Tab(props: Tab) {
  return (
    <Link className="w-full" href={props.href}>
      <div className="w-full flex flex-row justify-start items-center gap-8 p-5 rounded-lg hover:bg-charcoal-400 transition-all">
        <div className="text-2xl">{props.icon}</div>
        <p className="text-lg font-light">{props.name}</p>
      </div>
    </Link>
  );
}
