/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** map_create
*/

#include <rpg/map.h>
#include <rpg/grid.h>
#include <nep/nmem.h>

map_t *map_create(int width, int height)
{
    map_t *map = ncalloc(1, sizeof(map_t));

    map->size = (sfVector2f){width, height};
    map->grid = grid_create((sfVector2i){width, height}, \
    (sfVector2f){2.0f, 2.0f}, (sfVector2f){0, 0}, (sfVector2i){16, 16});
    map->sroll = (pos_t) {.0, .0};
    map->fondation = layer_create(map->size);
    map->houses = layer_create(map->size);
    map->objects = layer_create(map->size);
    map->props1 = layer_create(map->size);
    map->props2 = layer_create(map->size);
    map->trees1 = layer_create(map->size);
    map->trees2 = layer_create(map->size);
    map->trees3 = layer_create(map->size);
    map->info = layer_create(map->size);
    map->active_item_pos = (sfVector2f) {-1, -1};
    return map;
}