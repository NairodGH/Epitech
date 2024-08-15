/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static ssize_t game_calc_shortest_coord(size_t map_edge, size_t coord_a,
    size_t coord_b)
{
    ssize_t pos = 0;
    ssize_t neg = 0;

    pos = coord_a - coord_b;
    if (coord_a > coord_b) {
        coord_b += map_edge;
    } else if (coord_a < coord_b) {
        coord_a += map_edge;
    }
    neg = coord_a - coord_b;
    if (llabs(pos) < llabs(neg))
        return pos;
    return neg;
}

vector_t *game_calc_vector(size_t map_x, size_t map_y,
    pos_t *a, pos_t *b)
{
    vector_t *res = malloc(sizeof(vector_t));

    if (res == NULL)
        return NULL;
    res->x = game_calc_shortest_coord(map_x, a->x, b->x);
    res->y = game_calc_shortest_coord(map_y, a->y, b->y);
    return res;
}

size_t game_calc_angle_degrees(pos_t *a, pos_t *b)
{
    double tan_a = atan2((double)a->y, (double)a->x);
    double tan_b = atan2((double)b->y, (double)b->x);
    double res = (tan_b - tan_a) * (180.0 / M_PI);

    if (res < 0)
        res += 360.0;
    res -= 90.0;
    if (res < 0)
        res += 360.0;
    return (size_t)res;
}
