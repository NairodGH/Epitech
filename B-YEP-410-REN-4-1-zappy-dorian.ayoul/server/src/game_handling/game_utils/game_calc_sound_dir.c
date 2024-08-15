/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const size_t dir_tiles[][3] = {
    {TILE_ONE, 342, 18},
    {TILE_TWO, 18, 72},
    {TILE_THREE, 72, 108},
    {TILE_FOUR, 108, 162},
    {TILE_FIVE, 162, 198},
    {TILE_SIX, 198, 252},
    {TILE_SEVEN, 252, 288},
    {TILE_EIGHT, 288, 342},
};

static dir_tile_e game_angle_to_tile(size_t angle, direction_e dir)
{
    for (size_t i = 0; i < sizeof(dir_tiles) / sizeof(dir_tiles[0]); i++) {
        if (i == 0 && (angle > dir_tiles[i][1] || angle <= dir_tiles[i][2])) {
            return (dir_tile_e)dir_tiles[(i + (dir * 2)) % 8][0];
        } else if (angle > dir_tiles[i][1] && angle <= dir_tiles[i][2]) {
            return (dir_tile_e)dir_tiles[(i + (dir * 2)) % 8][0];
        }
    }
    return TILE_NONE;
}

dir_tile_e game_calc_direction(map_t *map, direction_e dir, pos_t *a,
    pos_t *b)
{
    vector_t *vector = NULL;
    size_t angle = 0;
    pos_t origin = {0, 0};

    vector = game_calc_vector(map->width, map->height, a, b);
    if (vector == NULL) {
        fprintf(stderr, "[ERROR] Failed to calculate vector\n");
        return TILE_NONE;
    }
    if (vector->x == 0 && vector->y == 0) {
        free(vector);
        return TILE_ZERO;
    }
    angle = game_calc_angle_degrees(&origin, (pos_t *)vector);
    free(vector);
    return game_angle_to_tile(angle, dir);
}
