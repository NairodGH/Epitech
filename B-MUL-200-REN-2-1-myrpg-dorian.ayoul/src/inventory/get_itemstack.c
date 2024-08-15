/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

itemstack_t *get_itemstack(game_t *game, int id)
{
    itemstack_t *itemstack;
    list_t *inventory = get_inventory(game);

    if (inventory == NULL)
        return (NULL);
    list_foreach(inventory, node) {
        itemstack = (itemstack_t *) node->value;
        if (itemstack == NULL || itemstack->item == NULL)
            continue;
        if (id == itemstack->item->id)
            return (itemstack);
    }
    return (NULL);
}