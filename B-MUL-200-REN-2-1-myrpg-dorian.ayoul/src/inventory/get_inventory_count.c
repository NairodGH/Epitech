/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_inventory_count
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

unsigned int get_inventory_count(game_t *game)
{
    unsigned int count = 0;
    itemstack_t *itemstack = NULL;
    list_t *inventory = get_inventory(game);

    if (!inventory)
        return (count);
    list_foreach(inventory, node) {
        itemstack = (itemstack_t *) node->value;
        if (itemstack == NULL)
            continue;
        ++count;
    }
    return (count);
}