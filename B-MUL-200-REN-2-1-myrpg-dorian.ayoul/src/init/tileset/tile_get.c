/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset_create
*/

#include <rpg/tileset.h>

PRIVATE void init_zero(sfIntRect *rect)
{
    rect->left = 0;
    rect->top = 0;
}

sfIntRect get_tile(tileset_t *tileset, int tile_id, sfIntRect *original)
{
    sfIntRect rect;

    if (original != NULL)
        rect = *original;
    init_zero(&rect);
    if (tile_id <= 0)
        return rect;
    for (int i = 0; i < tile_id; i++) {
        rect.left += tileset->info.cell_width;
        if ((uint)rect.left >= tileset->texture_size.x) {
            rect.left = 0;
            rect.top += tileset->info.cell_height;
        }
        if ((uint)rect.top >= tileset->texture_size.y) {
            init_zero(&rect);
            break;
        }
    }
    return rect;
}