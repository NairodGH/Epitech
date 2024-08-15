/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

void debug_inventory(game_t *game)
{
    itemstack_t *itemstack;
    item_t *item;
    list_t *inv = get_inventory(game);
    int i = 0;

    if (inv == NULL) {
        nprintf("No inventory.\n");
        return;
    }
    list_foreach(inv, node) {
        itemstack = (itemstack_t *) node->value;
        item = itemstack->item;
        nprintf("Slot_id: %d => ", i);
        nprintf("Item [id: %d | max_stack: %d] ", item->id, item->max_stack);
        nprintf("| Count: %d\n", itemstack->count);
        ++i;
    }
}