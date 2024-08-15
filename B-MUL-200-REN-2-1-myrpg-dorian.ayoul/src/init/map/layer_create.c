/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** layer_create
*/

#include <rpg/map.h>
#include <nep/nmem.h>

map_tile_t **layer_create(sfVector2f size)
{
    map_tile_t **layer = ncalloc(size.y + 1, sizeof(map_tile_t *));

    for (int y = 0; y < size.y; y++) {
        layer[y] = ncalloc(size.x + 1, sizeof(map_tile_t));
        for (int x = 0; x < size.x; x++)
            layer[y][x].tile_id = 0;
    }
    return layer;
}