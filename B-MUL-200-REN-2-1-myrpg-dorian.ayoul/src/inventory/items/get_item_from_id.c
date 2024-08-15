/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_item_from_id
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <file_utils.h>

item_t *get_item_from_id(game_t *game, int id)
{
    item_t *item;

    if (game == NULL || game->items == NULL)
        return (NULL);
    list_foreach(game->items, node) {
        item = (item_t *) node->value;
        if (item->id != id)
            continue;
        return (item);
    }
    return (NULL);
}