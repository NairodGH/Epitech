/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** map_free
*/

#include <rpg/rpg.h>

void map_free(map_t *map)
{
    if (map == NULL)
        return;
    layer_free(map->fondation, map->size);
    layer_free(map->houses, map->size);
    layer_free(map->objects, map->size);
    layer_free(map->props1, map->size);
    layer_free(map->props2, map->size);
    layer_free(map->trees1, map->size);
    layer_free(map->trees2, map->size);
    layer_free(map->trees3, map->size);
    layer_free(map->info, map->size);
    free(map->grid);
    free(map);
}