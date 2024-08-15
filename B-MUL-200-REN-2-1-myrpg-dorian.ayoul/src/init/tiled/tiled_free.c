/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled_free
*/

#include <rpg/tiled.h>

void tiled_free(tiled_map_t *map)
{
    if (map == NULL)
        return;
    if (map->tilesets != NULL) {
        list_foreach(map->tilesets, node)
            free(((tiled_tileset_t *)node->value)->name);
        list_free(map->tilesets);
    }
    if (map->layers != NULL) {
        hashmap_foreach(map->layers, node)
            free(node->value);
        hashmap_free(map->layers);
    }
    free(map);
}