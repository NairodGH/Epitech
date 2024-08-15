/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add_inventory_item
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

list_t *get_inventory(game_t *game)
{
    if (game == NULL || game->player == NULL)
        return (NULL);
    return (game->player->inventory);
}