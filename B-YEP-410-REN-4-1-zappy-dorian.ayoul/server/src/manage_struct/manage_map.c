/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "map.h"

map_t *map_create(size_t width, size_t height)
{
    map_t *map = calloc(1, sizeof(map_t));

    if (map == NULL)
        return NULL;
    map->width = width;
    map->height = height;
    map->map = calloc(width * height, sizeof(inventory_t *));
    if (map->map == NULL)
        return NULL;
    for (size_t i = 0; i < width * height; i++) {
        map->map[i] = inventory_create();
        if (map->map[i] == NULL)
            return NULL;
    }
    return map;
}

void map_destroy(map_t *map)
{
    if (map == NULL)
        return;
    for (size_t i = 0; i < map->width * map->height; i++) {
        if (map->map[i])
            inventory_destroy(map->map[i]);
    }
    free(map->map);
    free(map);
}
