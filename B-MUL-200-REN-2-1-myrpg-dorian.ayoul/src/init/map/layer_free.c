/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** layer_create
*/

#include <rpg/map.h>
#include <stdlib.h>

PRIVATE void free_tile(map_tile_t *tile)
{
    sfSprite_destroy(tile->sprite);
    free(tile->tileset_id);
}

void layer_free(map_tile_t **layer, sfVector2f size)
{
    if (layer == NULL)
        return;
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++)
            free_tile(&layer[y][x]);
        free(layer[y]);
    }
    free(layer);
}