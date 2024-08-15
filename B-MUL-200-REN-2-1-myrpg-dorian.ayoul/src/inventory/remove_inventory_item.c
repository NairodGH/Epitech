/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE int pop_iscount(list_t *ls, list_node_t *nd, itemstack_t *st, int cu)
{
    if (st == NULL || ls == NULL)
        return (cu);
    if (st->count <= cu) {
        cu -= st->count;
        st->count = 0;
        list_remove(ls, nd);
        return (cu);
    }
    st->count -= cu;
    return (0);
}

bool remove_inventory_item(game_t *game, item_t *item, int count)
{
    itemstack_t *stack = NULL;
    int current = count;
    list_t *inv;

    if (item == NULL || game == NULL || count > item->max_stack)
        return (false);
    inv = game->player->inventory;
    if (count < 1 || inv == NULL)
        return (false);
    list_foreach(inv, node) {
        stack = (itemstack_t *) node->value;
        if (stack == NULL || stack->item == NULL || stack->item != item)
            continue;
        if (current <= 0)
            return (true);
        current = pop_iscount(inv, node, stack, current);
    }
    return (current <= 0);
}

bool remove_item_from_id(game_t *game, int item_id, int count)
{
    item_t *item;

    if (game == NULL)
        return (false);
    item = get_item_from_id(game, item_id);
    if (item == NULL)
        return (false);
    return (remove_inventory_item(game, item, count));
}