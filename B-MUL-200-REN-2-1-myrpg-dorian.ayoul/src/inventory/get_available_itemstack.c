/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

itemstack_t *get_available_itemstack(game_t *game, item_t *item, int ncount)
{
    itemstack_t *itemstack;
    list_t *inventory = get_inventory(game);

    if (inventory == NULL || item == NULL)
        return (NULL);
    list_foreach(inventory, node) {
        itemstack = (itemstack_t *) node->value;
        if (itemstack->item != item)
            continue;
        if (itemstack->count + ncount > item->max_stack)
            continue;
        return (itemstack);
    }
    return (NULL);
}