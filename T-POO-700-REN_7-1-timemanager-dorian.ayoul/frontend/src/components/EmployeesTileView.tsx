import TileView from "devextreme-react/tile-view";
import { ItemClickEvent } from "devextreme/ui/tile_view_types";
import { useRouter } from "next/navigation";
import Button from "devextreme-react/button";
import Popup from "devextreme-react/popup";
import { FormEvent, useState } from "react";
import dxPopup from "devextreme/ui/popup";
import { InitializedEvent } from "devextreme/ui/popup_types";
import { Form } from "devextreme-react";
import { ButtonItem, GroupItem, RequiredRule, SimpleItem } from "devextreme-react/form";
import { User, userUpdateTeam, users } from "@/api/endpoints/user";
import { useMutation, useQuery, useQueryClient } from "react-query";
import { useNotify } from "@/hooks/useNotify";

type EmployeesTileViewProps = {
  employees: User[];
  id?: string;
};

export default function EmployeesTileView(props: EmployeesTileViewProps) {
  const router = useRouter();
  const queryClient = useQueryClient();
  const notify = useNotify();
  const [formInstance, setFormInstance] = useState<dxPopup | undefined>(undefined);

  const { data: employeesData } = useQuery({
    queryKey: "team/employees",
    queryFn: users,
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
  });

  const linkUserMutation = useMutation({
    mutationKey: "team/linkUser",
    mutationFn: ({ userId, teamId }: { userId: string; teamId: string }) => userUpdateTeam({ userId, teamId }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: () => {
      notify("The employee has been added to the team", "success");
      queryClient.invalidateQueries("team/teamEmployees");
      queryClient.invalidateQueries("team/clocks");
      formInstance?.toggle(false);
    },
  });

  function onInitialized(initializedEvent: InitializedEvent) {
    setFormInstance(initializedEvent.component);
  }

  const itemRender = (itemData: User) => {
    return (
      <div className="w-full h-full select-none flex flex-col justify-evenly text-center">
        <div className="dx-icon dx-icon-user" />
        <div>
          {itemData.firstname} {itemData.lastname}
        </div>
        <div>{itemData.role}</div>
      </div>
    );
  };

  function onItemClick(e: ItemClickEvent) {
    router.push(`/employee/${e.itemData.id}`);
  }

  function onButtonClick() {
    formInstance?.toggle(true);
  }

  function handleSubmit(formEvent: FormEvent<HTMLFormElement>) {
    formEvent.preventDefault();
    linkUserMutation.mutate({ userId: (formEvent.target as any).employee.value, teamId: props.id! });
  }

  function getSelectOptions() {
    const dataSource = employeesData?.data.filter((employee) => employee.team !== props.id) ?? [];
    const valueExpr = "id";
    const displayExpr = (item?: User) => (item ? `${item.firstname} ${item.lastname}` : "");
    const noDataText = "No valid employee available";
    return { dataSource, valueExpr, displayExpr, noDataText };
  }

  function contentRender() {
    return (
      <form action="/addemployee" onSubmit={handleSubmit}>
        <Form showColonAfterLabel={true}>
          <GroupItem caption="Add an employee to the team" cssClass="text-center">
            <SimpleItem dataField="employee" editorType="dxSelectBox" editorOptions={getSelectOptions()}>
              <RequiredRule message="Employee is required" />
            </SimpleItem>
            <ButtonItem
              horizontalAlignment="left"
              cssClass="flex justify-center"
              buttonOptions={{
                text: "Add the employee",
                type: "success",
                useSubmitBehavior: true,
              }}
            />
          </GroupItem>
        </Form>
      </form>
    );
  }

  return (
    <div>
      <Popup
        dragEnabled={false}
        hideOnOutsideClick={true}
        showCloseButton={false}
        onInitialized={onInitialized}
        contentRender={contentRender}
      />
      <div className="flex flex-col gap-5">
        {props.id && <Button icon="add" text="Add an employee" type="default" onClick={onButtonClick} />}
        <TileView
          items={props.employees}
          itemRender={itemRender}
          direction="vertical"
          baseItemHeight={200}
          baseItemWidth={200}
          onItemClick={onItemClick}
          noDataText=""
        />
      </div>
    </div>
  );
}
