/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

itemstack_t *create_itemstack(item_t *item, int item_count)
{
    itemstack_t *itemstack;

    if (item == NULL || item_count > item->max_stack)
        return (NULL);
    itemstack = ncalloc(1, sizeof(itemstack_t));
    if (itemstack == NULL)
        return (NULL);
    itemstack->item = item;
    itemstack->count = item_count;
    return (itemstack);
}