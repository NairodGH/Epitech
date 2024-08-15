import notify from "devextreme/ui/notify";

export type UseNotifyReturn = (message: string, type: "success" | "error", duration: number) => void;

export function useNotify() {
  return (message: string, type: "success" | "error", duration = 3000) => {
    const pos = {
      my: "center top",
      at: "top right",
    };
    notify(
      {
        message,
        position: pos,
      },
      type,
      duration,
    );
  };
}
