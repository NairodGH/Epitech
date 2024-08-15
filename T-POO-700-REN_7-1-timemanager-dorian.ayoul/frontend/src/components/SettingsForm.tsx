import Form, {
  Label,
  ButtonItem,
  GroupItem,
  SimpleItem,
  RequiredRule,
  StringLengthRule,
  CompareRule,
  PatternRule,
} from "devextreme-react/form";
import Validator from "devextreme/ui/validator";
import { InitializedEvent } from "devextreme/ui/form_types";
import dxForm from "devextreme/ui/form";
import { FormEvent, useState } from "react";
import { useRouter } from "next/navigation";
import { useNotify } from "@/hooks/useNotify";
import { UserAction, userDelete, userUpdate } from "@/api/endpoints/user";
import { useJWT } from "@/hooks/useJWT";
import { useMutation } from "react-query";

type SettingsFormProps = {
  employee: UserAction;
};

export default function SettingsForm(props: SettingsFormProps) {
  const router = useRouter();
  const notify = useNotify();
  const { id } = useJWT();
  const updateUserMutation = useMutation({
    mutationKey: "update",
    mutationFn: ({ id, email, password, firstname, lastname }: UserAction & { id: string }) =>
      userUpdate({ id, email, password, firstname, lastname }),
    onError: (err) => {
      notify((err as any).message ?? "An error occurred", "error");
    },
    onSuccess: () => {
      notify("Account updated", "success");
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
      router.push("/login");
    },
  });

  const [formInstance, setFormInstance] = useState<dxForm | undefined>(undefined);

  function onInitialized(initializedEvent: InitializedEvent) {
    setFormInstance(initializedEvent.component);
  }

  function changePasswordMode(name: string) {
    const editor = formInstance?.getEditor(name);
    if (editor) editor.option("mode", editor.option("mode") === "text" ? "password" : "text");
  }

  function passwordComparison() {
    return formInstance?.getEditor("newPassword")?.option("value");
  }

  function filterValue(value: string) {
    return value === "" || !value ? undefined : value;
  }

  async function handleSubmit(formEvent: FormEvent<HTMLFormElement>) {
    formEvent.preventDefault();

    // set empty string to undefined
    updateUserMutation.mutate({
      id: id!,
      password: filterValue((formEvent.target as any)?.passwordField?.value),
      firstname: filterValue((formEvent.target as any)?.firstname?.value),
      lastname: filterValue((formEvent.target as any)?.lastname?.value),
    });
  }

  function handleDelete() {
    deleteMutation.mutate({ id: id! });
  }

  return (
    <div className="flex items-center">
      <form action="/settings" onSubmit={handleSubmit}>
        <Form formData={props.employee} onInitialized={onInitialized} showColonAfterLabel={true}>
          <GroupItem caption="Settings" cssClass="text-center">
            <SimpleItem dataField="firstname">
              <Label text="First name" />
              <PatternRule message="Do not use digits in the name" pattern={/^[^0-9]+$/} />
            </SimpleItem>
            <SimpleItem dataField="lastname">
              <Label text="Last name" />
              <PatternRule message="Do not use digits in the name" pattern={/^[^0-9]+$/} />
            </SimpleItem>
            <SimpleItem
              name="newPassword"
              dataField="passwordField"
              editorType="dxTextBox"
              editorOptions={{
                mode: "password",
                onValueChanged: () => {
                  if (formInstance) {
                    const editor = formInstance.getEditor("confirmNewPassword");
                    if (editor?.option("value")) {
                      const instance = Validator.getInstance(editor.element()) as Validator;
                      instance.validate();
                    }
                  }
                },
                buttons: [
                  {
                    name: "password",
                    location: "after",
                    options: {
                      icon: "eyeopen",
                      type: "default",
                      onClick: () => changePasswordMode("newPassword"),
                    },
                  },
                ],
              }}
            >
              <Label text="New password" />
              {passwordComparison() && <StringLengthRule min={8} message="Passwords must be at least 8 characters" />}
            </SimpleItem>
            <SimpleItem
              name="confirmNewPassword"
              editorType="dxTextBox"
              editorOptions={{
                mode: "password",
                buttons: [
                  {
                    name: "password",
                    location: "after",
                    options: {
                      icon: "eyeopen",
                      type: "default",
                      onClick: () => changePasswordMode("confirmNewPassword"),
                    },
                  },
                ],
              }}
            >
              <Label text="Confirm new password" />
              {passwordComparison() && <RequiredRule message="Confirm new password is required" />}
              <CompareRule message="Password and Confirm password do not match" comparisonTarget={passwordComparison} />
            </SimpleItem>
            <ButtonItem
              horizontalAlignment="center"
              buttonOptions={{
                text: "Save",
                type: "success",
                useSubmitBehavior: true,
              }}
            />
            <ButtonItem
              horizontalAlignment="center"
              buttonOptions={{
                text: "Delete account",
                type: "danger",
                onClick: handleDelete,
              }}
            />
          </GroupItem>
        </Form>
      </form>
    </div>
  );
}
