/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** remove_itemstack
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE bool rm_stack(list_t *ls, list_node_t *nd, itemstack_t *st, int cn)
{
    if (!st)
        return (false);
    if (st->count <= cn) {
        list_remove(ls, nd);
        return (true);
    }
    st->count -= cn;
    return (true);
}

bool remove_itemstack(game_t *game, itemstack_t *itemstack, int count)
{
    itemstack_t *its;
    list_t *inventory;

    if (game == NULL || itemstack == NULL)
        return (false);
    inventory = get_inventory(game);
    if (game->player == NULL || inventory == NULL)
        return (false);
    list_foreach(inventory, node) {
        its = (itemstack_t *) node->value;
        if (its == NULL)
            continue;
        if (its == itemstack)
            return (rm_stack(inventory, node, its, count));
    }
    return (false);
}