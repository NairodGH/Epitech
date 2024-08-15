/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE bool add_itemstack(game_t *game, item_t *item, int count)
{
    list_t *inv;
    itemstack_t *stack = create_itemstack(item, count);

    if (stack == NULL)
        return (false);
    inv = game->player->inventory;
    if (inv == NULL)
        return (false);
    list_add(inv, stack);
    return (true);
}

bool add_inventory_item(game_t *game, item_t *item, int count)
{
    itemstack_t *available = NULL;

    if (item == NULL || count < 1 || count > item->max_stack)
        return (false);
    if (game == NULL || game->player->inventory == NULL)
        return (false);
    if (game->player->inventory == NULL) {
        game->player->inventory = list_create();
        if (!get_inventory(game))
            return (false);
    }
    available = get_available_itemstack(game, item, count);
    if (available == NULL)
        return (add_itemstack(game, item, count));
    available->count += count;
    return (true);
}

bool give_item(game_t *game, int item_id, int count)
{
    item_t *item;

    if (game == NULL)
        return (false);
    item = get_item_from_id(game, item_id);
    if (item == NULL)
        return (false);
    return (add_inventory_item(game, item, count));
}