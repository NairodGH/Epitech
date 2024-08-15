/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save attributes
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <engine.h>
#include <envdata.h>
#include <file_utils.h>
#include <hnep/nstring.h>

void save_item(itemstack_t *itemstack, xml_balise_t *inv)
{
    xml_balise_t *slot = xml_add_balise(inv, "slot");
    char *item_id;
    char *count;

    if (itemstack->item == NULL)
        return;
    item_id = string_format("%i", itemstack->item->id);
    count = string_format("%i", itemstack->count);
    xml_add_attribute(slot, "item-id", item_id);
    xml_add_attribute(slot, "count", count);
    free(item_id);
    free(count);
}

void save_inventory(list_t *list, xml_balise_t *content)
{
    xml_balise_t *inv;

    if (list == NULL || content == NULL)
        return;
    inv = xml_add_balise(content, "inventory");
    list_foreach(list, node)
        save_item((itemstack_t *)node->value, inv);
}

void save_save_inventory(save_t *save, xml_balise_t *content)
{
    if (!save || !save->inventory)
        return;
    save_inventory(save->inventory, content);
}

void save_player_inventory(player_t *player, xml_balise_t *content)
{
    if (!player || !player->inventory)
        return;
    save_inventory(player->inventory, content);
}