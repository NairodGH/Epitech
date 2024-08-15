/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset_create
*/

#include <rpg/tileset.h>
#include <nep/nmem.h>

tileset_t *tileset_create(char const *file_path, tileset_info_t info)
{
    tileset_t *tileset = ncalloc(1, sizeof(tileset_t));

    tileset->texture = sfTexture_createFromFile(file_path, NULL);
    tileset->texture_size = sfTexture_getSize(tileset->texture);
    tileset->info = info;
    return tileset;
}