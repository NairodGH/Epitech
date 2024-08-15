/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** register_tileset
*/

#include <rpg/rpg.h>

void register_tileset(game_t *game)
{
    game->tilesets = hashmap_create();
    tileset_register(game, "rpg_tileset", "assets/textures/tilesets/" \
    "rpg_tileset.png", (tileset_info_t){16, 16, 1});
    tileset_register(game, "info_tileset", "assets/textures/tilesets/" \
    "info_tileset.png", (tileset_info_t){16, 16, 1});
}