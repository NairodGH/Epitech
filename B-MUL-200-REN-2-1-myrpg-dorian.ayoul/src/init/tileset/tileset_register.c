/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset_create
*/

#include <rpg/rpg.h>

tileset_t *tileset_register(game_t *game, char const *name,
char const *file_path, tileset_info_t info)
{
    tileset_t *tileset = tileset_create(file_path, info);

    hashmap_add(game->tilesets, name, tileset);
    return tileset;
}