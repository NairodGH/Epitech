/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

void print_vector(Vector2 *pos)
{
    size_t i = 0;

    while (pos[i].x != 0 && pos[i].y != 0) {
        printf("x = %0f | y = %0f\n", pos[i].x, pos[i].y);
        i++;
    }
}

Vector2 find_spawn_pos(char cell, char **map)
{
    Vector2 ret = {0, 0};

    for (size_t x = 0; map[x] != NULL; x++) {
        for (size_t y = 0; map[x][y] != '\0'; y++) {
            if (map[x][y] == cell) {
                ret.x = x;
                ret.y = y;
                return (ret);
            }
        }
    }
}

int get_map_size(char **map)
{
    int ret = 0;

    while (map[ret] != NULL)
        ret++;
    return ret;
}

void print_double_tab(char **map)
{
    for (size_t x = 0; map[x] != NULL; x++)
        printf("%s\n", map[x]);
}

void free_double_tab(char **map)
{
    for (size_t x = 0; map[x] != NULL; x++)
        free(map[x]);
    free(map);
}