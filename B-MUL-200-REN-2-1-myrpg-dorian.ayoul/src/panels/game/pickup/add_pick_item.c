/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** add pick item
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void add_pick_item(game_t *game, map_tile_t *tile, sfVector2f pos)
{
    posint_t *posint = ncalloc(1, sizeof(posint_t));

    if (!game || !tile || !posint)
        return;
    tile->tile_id = 0;
    tile->texture = NULL;
    tile->sprite = NULL;
    posint->x = (int) pos.x;
    posint->y = (int) pos.y;
    if (!game || !game->player)
        return;
    if (!game->player->pickitems)
        game->player->pickitems = list_create();
    list_add(game->player->pickitems, posint);
}