/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Get player tile
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

sfVector2i get_player_tile_pos(map_t *map, obj_t *obj)
{
    int rel_tilex;
    int rel_tiley;
    sfVector2f pos;
    pos_t scroll;

    if (map == NULL || obj == NULL)
        return ((sfVector2i) {0, 0});
    pos = obj->pos;
    rel_tilex = (int) (pos.x / 16.f);
    rel_tiley = (int) (pos.y / 16.f);
    scroll = map->sroll;
    scroll.x += rel_tilex - 14;
    scroll.y += rel_tiley - 5;
    return ((sfVector2i) {scroll.x, scroll.y});
}

int get_player_tile(map_t *map, obj_t *obj)
{
    map_tile_t *tile = NULL;
    sfVector2i tile_pos;

    if (map == NULL || obj == NULL)
        return (-1);
    tile_pos = get_player_tile_pos(map, obj);
    tile = &map->fondation[tile_pos.y][tile_pos.x];
    if (tile == NULL)
        return (-1);
    return (tile->tile_id);
}