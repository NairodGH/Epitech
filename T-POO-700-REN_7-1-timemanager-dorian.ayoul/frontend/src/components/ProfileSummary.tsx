import { User, UserUpdate, userDelete, userUpdate } from "@/api/endpoints/user";
import { useJWT } from "@/hooks/useJWT";
import Button from "devextreme-react/button";
import notify from "devextreme/ui/notify";
import { useRouter } from "next/navigation";
import { useMutation, useQueryClient } from "react-query";

type ProfileSummaryProps = {
  employee: User;
};

function EmployeeRoleButtons(props: {
  role?: string;
  onPromoteButtonClick: () => void;
  onDemoteButtonClick: () => void;
  onDeleteButtonClick: () => void;
}) {
  const { onDeleteButtonClick, onPromoteButtonClick, onDemoteButtonClick } = props;
  const { role: personnalRole } = useJWT();

  if (personnalRole !== "admin") return <></>;

  return (
    <div className="flex flex-col justify-evenly">
      {props.role == "employee" ? (
        <Button icon="arrowup" text="Promote to manager" type="default" onClick={onPromoteButtonClick} />
      ) : (
        <Button icon="arrowdown" text="Demote to employee" type="normal" onClick={onDemoteButtonClick} />
      )}
      <Button text="Delete account" type="danger" onClick={onDeleteButtonClick} />
    </div>
  );
}

export default function ProfileSummary(props: ProfileSummaryProps) {
  const { id } = useJWT();
  const router = useRouter();
  const queryClient = useQueryClient();

  const updateUserMutation = useMutation({
    mutationKey: "update",
    mutationFn: ({ id, role }: UserUpdate) => userUpdate({ id, role }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: () => {
      notify("Account updated", "success");
      queryClient.invalidateQueries("employee/info");
      queryClient.invalidateQueries("dashboard/userInfo");
    },
  });
  const deleteMutation = useMutation({
    mutationKey: "delete",
    mutationFn: ({ id }: { id: string }) => userDelete({ id }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: () => {
      notify("Account deleted", "success");
      router.push("/employees");
    },
  });

  function onPromoteButtonClick() {
    if (id === props.employee.id) {
      notify("You can't promote yourself", "error");
      return;
    }
    if (props.employee.role === "manager") {
      notify("This user is already a manager", "error");
    } else {
      updateUserMutation.mutate({ id: props.employee.id, role: "manager" });
    }
  }

  function onDemoteButtonClick() {
    if (id === props.employee.id) {
      notify("You can't demote yourself", "error");
      return;
    }
    if (props.employee.role === "employee") {
      notify("This user is already a employee", "error");
    } else {
      updateUserMutation.mutate({ id: props.employee.id, role: "employee" });
    }
  }

  function onDeleteButtonClick() {
    if (id === props.employee.id) {
      notify("You can't delete yourself", "error");
      return;
    }
    deleteMutation.mutate({ id: props.employee.id! });
  }

  return (
    <div className="text-center flex flex-col justify-evenly p-4">
      <div>
        {props.employee.firstname} {props.employee.lastname}
      </div>
      <div>{props.employee.email}</div>
      <EmployeeRoleButtons
        role={props.employee.role}
        onPromoteButtonClick={onPromoteButtonClick}
        onDemoteButtonClick={onDemoteButtonClick}
        onDeleteButtonClick={onDeleteButtonClick}
      />
    </div>
  );
}
