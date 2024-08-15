/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Remove pickitems
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void remove_pickitems(game_t *game)
{
    posint_t *pos;
    map_t *map;

    if (!game || !game->player || !game->player->pickitems)
        return;
    map = game->stage->map;
    list_foreach(game->player->pickitems, node) {
        pos = (posint_t *) node->value;
        if (!pos)
            continue;
        if (pos->x > map->size.x || pos->y > map->size.y)
            continue;
        map->objects[pos->y][pos->x].tile_id = 0;
        map->objects[pos->y][pos->x].texture = NULL;
        map->objects[pos->y][pos->x].sprite = NULL;
    }
}