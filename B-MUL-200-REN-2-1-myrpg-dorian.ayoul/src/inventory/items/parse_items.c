/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <file_utils.h>
#include <objects.h>

PRIVATE obj_t *create_item_object(item_t *item, bool extended_tooltip)
{
    obj_t *obj;
    sfVector2f pos = {0, 0};
    char *tl = NULL;

    if (item == NULL || item->asset_image == NULL)
        return (NULL);
    obj = create_object(item->asset_image, item->asset_rect, pos);
    set_obj_type(obj, OBJ_INVENTORY_ITEM);
    set_obj_events(obj, &on_item_click);
    if (extended_tooltip) {
        tl = append_str(append_str(item->name, "\n\n"), item->description);
    } else {
        tl = item->name;
    }
    set_obj_tooltip(obj, tl);
    return (obj);
}

PRIVATE item_t *parse_item_asset(item_t *item, char *xml)
{
    char *asset;
    char *image;
    char *rect;

    if (item == NULL || xml == NULL)
        return (NULL);
    asset = xml_get_balise(xml, "asset");
    if (asset == NULL)
        return (item);
    image = xml_get_balise(asset, "image");
    rect = xml_get_balise(asset, "rect");
    item->asset_image = xml_get_attribute(image, "src");
    item->asset_rect = parse_rect(rect);
    item->obj = create_item_object(item, false);
    item->obj_gui = create_item_object(item, true);
    return (item);
}

PRIVATE item_t *parse_item(char *xml)
{
    item_t *item = ncalloc(1, sizeof(item_t));
    char *attr = xml_get_balise(xml, "attributes");

    if (item == NULL || attr == NULL)
        return (NULL);
    item->id = natoi(xml_get_attribute(attr, "id"));
    item->max_stack = natoi(xml_get_attribute(attr, "max-stack"));
    item->tile = natoi(xml_get_attribute(attr, "tile"));
    item->category = natoi(xml_get_attribute(attr, "category"));
    item->name = xml_balcontent(xml, "name");
    item->description = xml_balcontent(xml, "description");
    item->description = replace_char(item->description, '@', '\n');
    item = parse_item_asset(item, xml);
    item = parse_item_consumable(item, xml);
    return (item);
}

PRIVATE list_t *parse_items(char *xml)
{
    list_t *list = list_create();
    char *itlist = xml_get_balise(xml, "items");
    char **items = itlist ? xml_get_balises(itlist, "item") : NULL;

    if (list == NULL)
        return (NULL);
    if (!itlist || !items)
        return (list);
    for (unsigned int itr = 1; items && items[itr]; ++itr)
        list_add(list, parse_item(items[itr]));
    free(items);
    return (list);
}

list_t *load_items(void)
{
    list_t *items;
    char *content = read_file("./config/items.xml");

    if (content == NULL)
        return (NULL);
    items = parse_items(content);
    free(content);
    return items;
}