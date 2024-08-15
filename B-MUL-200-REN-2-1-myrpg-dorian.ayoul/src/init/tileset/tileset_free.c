/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset_free
*/

#include <rpg/rpg.h>

void tileset_free(tileset_t *tileset)
{
    if (tileset == NULL)
        return;
    sfTexture_destroy(tileset->texture);
    free(tileset);
}

void tilesets_free(hashmap_t *tilesets)
{
    if (tilesets == NULL)
        return;
    hashmap_foreach(tilesets, node)
        tileset_free((tileset_t *)node->value);
    hashmap_free(tilesets);
}