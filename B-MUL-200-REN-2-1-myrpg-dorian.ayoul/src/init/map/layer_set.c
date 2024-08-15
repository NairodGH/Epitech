/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** layer_fill
*/

#include <rpg/rpg.h>

PRIVATE void tile_init(map_tile_t *tile, hashmap_t *tilesets)
{
    tileset_t *tileset = tileset_get(tilesets, tile->tileset_id);

    if (tileset == NULL)
        return;
    tile->sprite = sfSprite_create();
    tile->texture = tileset->texture;
    sfSprite_setTexture(tile->sprite, tile->texture, sfTrue);
    tile->rect = get_tile(tileset, tile->tile_id, NULL);
    tile->rect.width = tileset->info.cell_width;
    tile->rect.height = tileset->info.cell_height;
    sfSprite_setTextureRect(tile->sprite, tile->rect);
}

void layer_set(map_tile_t **layer, sfVector2f size, hashmap_t *tilesets)
{
    if (layer == NULL)
        return;
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++)
            tile_init(&layer[y][x], tilesets);
    }
}