import { clockCreate } from "@/api/endpoints/clock";
import { UserAction } from "@/api/endpoints/user";
import { useJWT } from "@/hooks/useJWT";
import { useNotify } from "@/hooks/useNotify";
import Button from "devextreme-react/button";
import { useState } from "react";
import { useMutation } from "react-query";

type ClockInOutButtonProps = {
  employee: UserAction;
};

export default function ClockInOutButton(props: ClockInOutButtonProps) {
  const { id } = useJWT();
  const notify = useNotify();
  const [isClockIn, setIsClockIn] = useState(true);
  const mutation = useMutation({
    mutationKey: "clock",
    mutationFn: () => clockCreate({ user: id! }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: () => {
      notify("Successfully clocked " + (isClockIn ? "in" : "out"), "success");
    },
  });

  function onClick() {
    setIsClockIn(!isClockIn);
    mutation.mutate();
  }

  return (
    <div className="flex flex-col justify-evenly text-center p-4">
      <div>
        Welcome {props?.employee?.firstname} {props?.employee?.lastname}
      </div>
      <div>Please clock {isClockIn ? "in" : "out"}</div>
      <Button icon="clock" text={"Clock " + (isClockIn ? "in" : "out")} onClick={onClick} />
    </div>
  );
}
