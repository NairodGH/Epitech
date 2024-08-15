/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** layer_fill
*/

#include <rpg/rpg.h>

PRIVATE char *parse_layer(map_tile_t *line, sfVector2f size, char *tiled_layer)
{
    char buf[255];
    int i = 0;
    int x = 0;

    nmemset(buf, 0, 255);
    while (x  < size.x && *tiled_layer) {
        if (*tiled_layer == ',') {
            line[x].tile_id = natoi(buf);
            nmemset(buf, 0, 255);
            i = 0;
            x++;
        }
        if (nisdigit(*tiled_layer))
            buf[i++] = *tiled_layer;
        tiled_layer++;
    }
    if (*tiled_layer == 0)
        line[x].tile_id = natoi(buf);
    return tiled_layer;
}

PRIVATE void set_tile(map_tile_t *tile, list_t *tilesets)
{
    tiled_tileset_t *tileset;
    tiled_tileset_t *select_tileset = NULL;

    list_foreach(tilesets, node) {
        tileset = (tiled_tileset_t *)node->value;
        if (tile->tile_id >= tileset->firstgid) {
            select_tileset = tileset;
        } else {
            break;
        }
    }
    if (select_tileset == NULL)
        return;
    tile->tile_id -= select_tileset->firstgid;
    tile->tileset_id = nstrdup(select_tileset->name);
}

void layer_fill(map_tile_t **layer, sfVector2f size, char *tiled_layer, \
list_t *tilesets)
{
    if (tiled_layer == NULL)
        return;
    for (int y = 0; y < size.y; y++) {
        tiled_layer = parse_layer(layer[y], size, tiled_layer);
        for (int x = 0; x < size.x; x++)
            set_tile(&layer[y][x], tilesets);
    }
}