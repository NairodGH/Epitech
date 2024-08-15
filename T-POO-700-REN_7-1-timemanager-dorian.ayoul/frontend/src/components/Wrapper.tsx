import HeaderButtonGroup from "@/components/HeaderButtonGroup";
import { headerButtonGroup } from "@/vars/constants";
import { ReactNode } from "react";

export default function Wrapper({ children }: { children: ReactNode }) {
  return (
    <div className="min-w-screen min-h-screen bg-dark text-white">
      <HeaderButtonGroup items={headerButtonGroup} />
      <main>{children}</main>
    </div>
  );
}
