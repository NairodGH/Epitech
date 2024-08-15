import TileView from "devextreme-react/tile-view";
import { ItemClickEvent } from "devextreme/ui/tile_view_types";
import { useRouter } from "next/navigation";
import Button from "devextreme-react/button";
import { ClickEvent } from "devextreme/ui/button_types";
import { FormEvent, useState } from "react";
import Popup from "devextreme-react/popup";
import Form, { ButtonItem, GroupItem, RequiredRule, SimpleItem, StringLengthRule } from "devextreme-react/form";
import { InitializedEvent } from "devextreme/ui/popup_types";
import dxPopup from "devextreme/ui/popup";
import { Team, teamCreate } from "@/api/endpoints/team";
import { useMutation, useQueryClient } from "react-query";
import { useNotify } from "@/hooks/useNotify";
import { useJWT } from "@/hooks/useJWT";

type TeamsTileViewProps = {
  teams: Team[];
};

export default function TeamsTileView(props: TeamsTileViewProps) {
  const router = useRouter();
  const notify = useNotify();
  const { id } = useJWT();
  const queryClient = useQueryClient();
  const [formInstance, setFormInstance] = useState<dxPopup | undefined>(undefined);

  const mutationTeam = useMutation({
    mutationKey: "teams/add",
    mutationFn: (team: Team) => teamCreate(team),
    onError: (error: any) => {
      notify(error.message ?? "An error occured", "error");
    },
    onSuccess: () => {
      queryClient.invalidateQueries("teams/teams");
      queryClient.invalidateQueries("teams/personnalTeams");
      formInstance?.toggle(false);
    },
  });

  function onInitialized(initializedEvent: InitializedEvent) {
    setFormInstance(initializedEvent.component);
  }

  const itemRender = (itemData: Team) => {
    return (
      <div className="w-full h-full select-none flex flex-col justify-evenly text-center">
        <div className="dx-icon dx-icon-group" />
        <div>{itemData.name}</div>
      </div>
    );
  };

  function onItemClick(e: ItemClickEvent) {
    router.push("/team/" + e.itemData.id);
  }

  function onButtonClick(e: ClickEvent) {
    formInstance?.toggle(true);
  }

  function handleSubmit(formEvent: FormEvent<HTMLFormElement>) {
    formEvent.preventDefault();
    const name = new FormData(formEvent.currentTarget).get("name")!;
    mutationTeam.mutate({ name: name as string, manager: id! });
  }

  function contentRender() {
    return (
      <form action="/addteam" onSubmit={handleSubmit}>
        <Form showColonAfterLabel={true}>
          <GroupItem caption="Create a team" cssClass="text-center">
            <SimpleItem dataField="name" editorType="dxTextBox">
              <RequiredRule message="Team name is required" />
              <StringLengthRule min={8} message="Team name must be at least 8 characters long" />
            </SimpleItem>
            <ButtonItem
              horizontalAlignment="left"
              cssClass="flex justify-center"
              buttonOptions={{
                text: "Add the team",
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
        <Button icon="add" text="Add a team" type="default" onClick={onButtonClick} />
        <TileView
          direction="vertical"
          items={props.teams}
          itemRender={itemRender}
          onItemClick={onItemClick}
          baseItemHeight={200}
          baseItemWidth={200}
          noDataText=""
        />
      </div>
    </div>
  );
}
