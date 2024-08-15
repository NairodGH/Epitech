import { ButtonGroup } from "devextreme-react/button-group";
import { useRouter, usePathname } from "next/navigation";
import { ItemClickEvent } from "devextreme/ui/button_group_types";
import { useJWT } from "@/hooks/useJWT";
import { useEffect, useState } from "react";

type HeaderButtonGroupProps = {
  items: {
    icon: string;
    hint: string;
    role?: string;
  }[];
};

export default function HeaderButtonGroup(props: HeaderButtonGroupProps) {
  const router = useRouter();
  const pathName = usePathname().charAt(1).toUpperCase() + usePathname().slice(2);
  const { role, removeToken } = useJWT();

  const [renderedItems, setRenderedItems] = useState<typeof props.items>([]);

  function onItemClick(itemClickEvent: ItemClickEvent) {
    if (itemClickEvent.itemData.hint == "Disconnect") {
      removeToken();
      router.push("/login");
    } else router.push("/" + itemClickEvent.itemData.hint.toLowerCase());
  }

  useEffect(() => {
    setRenderedItems(
      props.items.filter((item) => {
        if (item.role == "admin") return role == "admin";
        else if (item.role == "manager") return role == "manager" || role == "admin";
        else return true;
      }),
    );
  }, [role, props.items]);

  return (
    <ButtonGroup
      items={renderedItems}
      keyExpr="hint"
      stylingMode="text"
      selectedItemKeys={[pathName]}
      onItemClick={onItemClick}
      width="100vw"
    />
  );
}
