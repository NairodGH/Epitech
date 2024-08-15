/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** map_create
*/

#include <rpg/rpg.h>

PRIVATE void map_fill_props(map_t *map, tiled_map_t *tiled_map, \
hashmap_t *tilesets)
{
    layer_fill(map->objects, map->size,
    tiled_get_layer(tiled_map, "Objects"), tiled_map->tilesets);
    layer_set(map->objects, map->size, tilesets);
    layer_fill(map->props1, map->size, \
    tiled_get_layer(tiled_map, "Props"), tiled_map->tilesets);
    layer_set(map->props1, map->size, tilesets);
    layer_fill(map->props2, map->size, \
    tiled_get_layer(tiled_map, "Props2"), tiled_map->tilesets);
    layer_set(map->props2, map->size, tilesets);
}

PRIVATE void map_fill_trees(map_t *map, tiled_map_t *tiled_map, \
hashmap_t *tilesets)
{
    layer_fill(map->trees1, map->size, \
    tiled_get_layer(tiled_map, "Trees1"), tiled_map->tilesets);
    layer_set(map->trees1, map->size, tilesets);
    layer_fill(map->trees2, map->size, \
    tiled_get_layer(tiled_map, "Trees2"), tiled_map->tilesets);
    layer_set(map->trees2, map->size, tilesets);
    layer_fill(map->trees3, map->size, \
    tiled_get_layer(tiled_map, "Trees3"), tiled_map->tilesets);
    layer_set(map->trees3, map->size, tilesets);
}

void map_fill(map_t *map, tiled_map_t *tiled_map, hashmap_t *tilesets)
{
    if (map == NULL || tiled_map == NULL)
        return;
    layer_fill(map->fondation, map->size, \
    tiled_get_layer(tiled_map, "Fondation"), tiled_map->tilesets);
    layer_set(map->fondation, map->size, tilesets);
    layer_fill(map->houses, map->size, \
    tiled_get_layer(tiled_map, "Houses"), tiled_map->tilesets);
    layer_set(map->houses, map->size, tilesets);
    map_fill_props(map, tiled_map, tilesets);
    map_fill_trees(map, tiled_map, tilesets);
    layer_fill(map->info, map->size, \
    tiled_get_layer(tiled_map, "Info"), tiled_map->tilesets);
    layer_set(map->info, map->size, tilesets);
}