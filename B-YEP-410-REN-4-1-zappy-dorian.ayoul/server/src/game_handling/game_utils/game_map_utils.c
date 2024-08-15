/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

size_t game_fill_map_dup(map_t *map, pos_t **pos)
{
    size_t x = 0;
    size_t y = 0;
    size_t remaining = 0;

    for (size_t i = 0; i < map->height * map->width; i++) {
        pos[remaining]->x = x;
        pos[remaining]->y = y;
        remaining++;
        if (x == map->width - 1) {
            x = 0;
            y++;
        } else {
            x++;
        }
    }
    return remaining;
}

size_t game_fill_map_dup_remaining(map_t *map, pos_t **pos,
    size_t idx_ressource)
{
    size_t x = 0;
    size_t y = 0;
    size_t remaining = 0;

    for (size_t i = 0; i < map->height * map->width; i++) {
        if (((size_t *)(map->map[i]))[idx_ressource] == 0) {
            pos[remaining]->x = x;
            pos[remaining]->y = y;
            remaining++;
        }
        if (x == map->width - 1) {
            x = 0;
            y++;
        } else {
            x++;
        }
    }
    return remaining;
}

void game_destroy_map_dup(map_t *map, pos_t **map_dup)
{
    for (size_t i = 0; i < map->height * map->width; i++)
        free(map_dup[i]);
    free(map_dup);
}

pos_t **game_init_map_dup(map_t *map)
{
    pos_t **pos = calloc(map->height * map->width, sizeof(pos_t *));

    if (pos == NULL)
        return NULL;
    for (size_t i = 0; i < map->height * map->width; i++) {
        pos[i] = calloc(1, sizeof(pos_t));
        if (pos[i] == NULL)
            return NULL;
    }
    return pos;
}

void game_map_dup_delete_idx(pos_t **map_dup, int idx, size_t remaining_tiles)
{
    pos_t *temp = map_dup[idx];

    map_dup[idx] = map_dup[remaining_tiles - 1];
    map_dup[remaining_tiles - 1] = temp;
}
