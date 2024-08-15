/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Player teleport
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

void player_teleport(game_t *game, int x, int y)
{
    map_t *map;

    if (!game || !game->stage)
        return;
    map = game->stage->map;
    if (!map)
        return;
    if (x < 0 || y < 0 || x > map->size.x || y > map->size.y)
        return;
    map->sroll.x = x;
    map->sroll.y = y;
}