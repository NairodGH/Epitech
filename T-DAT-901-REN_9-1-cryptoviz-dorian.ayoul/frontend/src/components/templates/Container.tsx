import { Card } from "@material-tailwind/react";
import { ReactNode } from "react";

type ContainerProps = {
  children: ReactNode;
  className?: string;
};

export default function Container(props: Readonly<ContainerProps>) {
  return (
    <Card>
      <div className={`p-10 ${props.className}`}>{props.children}</div>
    </Card>
  );
}
