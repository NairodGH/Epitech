import Form, {
  ButtonItem,
  GroupItem,
  SimpleItem,
  EmailRule,
  RequiredRule,
  StringLengthRule,
} from "devextreme-react/form";
import { loginForm } from "@/vars/constants";
import { InitializedEvent } from "devextreme/ui/form_types";
import dxForm from "devextreme/ui/form";
import { FormEvent, useState } from "react";
import { useRouter } from "next/navigation";
import { useNotify } from "@/hooks/useNotify";
import { useJWT } from "@/hooks/useJWT";
import { useMutation } from "react-query";
import { userLogin } from "@/api/endpoints/user";

export default function LoginForm() {
  const router = useRouter();
  const notify = useNotify();
  const { storeToken } = useJWT();
  const mutation = useMutation({
    mutationKey: "login",
    mutationFn: ({ email, password }: { email: string; password: string }) => userLogin({ email, password }),
    onError: (err) => {
      notify("Invalid email or password", "error");
    },
    onSuccess: onLoginSuccess,
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
    });
  }

  function onLoginSuccess(data: any) {
    const token = data?.data;

    if (!token) {
      notify("Something went wrong", "error", 3000);
    } else {
      storeToken(token);
      notify("Welcome back !", "success", 3000);
      router.push("/dashboard");
    }
  }

  return (
    <div className="flex items-center">
      <form action="/login" onSubmit={handleSubmit}>
        <Form formData={loginForm} onInitialized={onInitialized} showColonAfterLabel={true}>
          <GroupItem caption="Log in" cssClass="text-center">
            <SimpleItem dataField="email" editorType="dxTextBox">
              <RequiredRule message="Email is required" />
              <EmailRule message="Email is invalid" />
            </SimpleItem>
            <SimpleItem
              dataField="password"
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
                      onClick: () => changePasswordMode("password"),
                    },
                  },
                ],
              }}
            >
              <RequiredRule message="Password is required" />
              <StringLengthRule min={8} message="Password must be at least 8 characters" />
            </SimpleItem>
            <ButtonItem
              horizontalAlignment="left"
              cssClass="flex justify-center"
              buttonOptions={{
                text: "Log in",
                type: "success",
                useSubmitBehavior: true,
              }}
            />
          </GroupItem>
        </Form>
      </form>
    </div>
  );
}
