import Form, {
  Label,
  ButtonItem,
  GroupItem,
  SimpleItem,
  EmailRule,
  RequiredRule,
  StringLengthRule,
  CompareRule,
  PatternRule,
} from "devextreme-react/form";
import Validator from "devextreme/ui/validator";
import { registerForm } from "@/vars/constants";
import { InitializedEvent } from "devextreme/ui/form_types";
import dxForm from "devextreme/ui/form";
import { FormEvent, useState } from "react";
import { useRouter } from "next/navigation";
import { useMutation } from "react-query";
import { UserAction, userCreate } from "@/api/endpoints/user";
import { useNotify } from "@/hooks/useNotify";
import { useJWT } from "@/hooks/useJWT";

export default function RegisterForm() {
  const router = useRouter();
  const notify = useNotify();
  const { storeToken } = useJWT();
  const mutation = useMutation({
    mutationKey: "register",
    mutationFn: ({ email, password, firstname, lastname }: UserAction) =>
      userCreate({ email, password, firstname, lastname }),
    onError: (err) => {
      notify("Email already taken", "error");
    },
    onSuccess: onRegisterSuccess,
  });

  const [formInstance, setFormInstance] = useState<dxForm | undefined>(undefined);

  function onInitialized(initializedEvent: InitializedEvent) {
    setFormInstance(initializedEvent.component);
  }

  function changePasswordMode(name: string) {
    const editor = formInstance?.getEditor(name);
    if (editor) editor.option("mode", editor.option("mode") === "text" ? "password" : "text");
  }

  async function handleSubmit(formEvent: FormEvent<HTMLFormElement>) {
    formEvent.preventDefault();

    mutation.mutate({
      email: (formEvent.target as any).email.value,
      password: (formEvent.target as any).password.value,
      firstname: (formEvent.target as any).firstname.value,
      lastname: (formEvent.target as any).lastname.value,
    });
  }

  function passwordComparison() {
    return registerForm.password;
  }

  function onRegisterSuccess(data: any) {
    const token = data?.data;

    if (!token) {
      notify("Something went wrong", "error");
    } else {
      storeToken(token);
      notify("Welcome !", "success");
      router.push("/dashboard");
    }
  }

  return (
    <div className="flex items-center">
      <form action="/register" onSubmit={handleSubmit}>
        <Form formData={registerForm} onInitialized={onInitialized} showColonAfterLabel={true}>
          <GroupItem caption="Register" cssClass="text-center">
            <SimpleItem dataField="firstname" name="firstname">
              <Label text="First name" />
              <RequiredRule message="First name is required" />
              <PatternRule message="Do not use digits in the name" pattern={/^[^0-9]+$/} />
            </SimpleItem>
            <SimpleItem dataField="lastname" name="lastname">
              <Label text="Last name" />
              <RequiredRule message="Last name is required" />
              <PatternRule message="Do not use digits in the name" pattern={/^[^0-9]+$/} />
            </SimpleItem>
            <SimpleItem dataField="email" name="email" editorType="dxTextBox">
              <RequiredRule message="Email is required" />
              <EmailRule message="Email is invalid" />
            </SimpleItem>
            <SimpleItem
              dataField="password"
              name="password"
              editorType="dxTextBox"
              editorOptions={{
                mode: "password",
                onValueChanged: () => {
                  if (formInstance) {
                    const editor = formInstance.getEditor("confirmPassword");
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
                      onClick: () => changePasswordMode("password"),
                    },
                  },
                ],
              }}
            >
              <RequiredRule message="Password is required" />
              <StringLengthRule min={8} message="Password must be at least 8 characters" />
            </SimpleItem>
            <SimpleItem
              name="confirmPassword"
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
                      onClick: () => changePasswordMode("confirmPassword"),
                    },
                  },
                ],
              }}
            >
              <Label text="Confirm password" />
              <RequiredRule message="Confirm Password is required" />
              <CompareRule message="Password and Confirm Password do not match" comparisonTarget={passwordComparison} />
            </SimpleItem>
            <ButtonItem
              horizontalAlignment="center"
              buttonOptions={{
                text: "Register",
                type: "success",
                useSubmitBehavior: true,
                disabled: mutation.isLoading,
              }}
            />
          </GroupItem>
        </Form>
      </form>
    </div>
  );
}
