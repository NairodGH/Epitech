import { ReactNode } from "react";

type ContainerProps = {
  children: ReactNode;
  className?: string;
};

export default function Container(props: Readonly<ContainerProps>) {
  return (
    <div className={`bg-white p-10 rounded-xl ${props.className}`}>
      {props.children}
    </div>
  );
}
