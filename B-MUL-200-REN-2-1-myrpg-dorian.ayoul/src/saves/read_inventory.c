/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_saves
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void parse_saved_item(game_t *game, list_t *inv, char *xml)
{
    char *raw_id;
    char *raw_count;
    item_t *item;
    itemstack_t *stack;

    if (!xml)
        return;
    raw_id = xml_get_attribute(xml, "item-id");
    raw_count = xml_get_attribute(xml, "count");
    if (!nstr_isdigit(raw_id) || !nstr_isdigit(raw_count))
        return;
    item = get_item_from_id(game, natoi(raw_id));
    if (!item)
        return;
    stack = create_itemstack(item, natoi(raw_count));
    if (!stack)
        return;
    list_add(inv, stack);
}

save_t *read_inventory(game_t *game, save_t *save, char *xml)
{
    char *inv;
    char **slots;

    if (!save || !xml || !game)
        return (save);
    inv = xml_balcontent(xml, "inventory");
    save->inventory = list_create();
    if (!inv || !save->inventory)
        return (save);
    slots = xml_get_balises(inv, "slot");
    for (uint itr = 0; slots && slots[itr]; itr++)
        parse_saved_item(game, save->inventory, slots[itr]);
    return (save);
}