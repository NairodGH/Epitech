/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset
*/

#ifndef RPG_TILESET_H
#define RPG_TILESET_H

#include <nep/nctype.h>
#include <nep/nhashmap.h>
#include <SFML/Graphics.h>

typedef struct game_s game_t;

typedef struct tileset_info_s {
    int cell_width;
    int cell_height;
    int firstgid;
} tileset_info_t;

typedef struct tileset_s {
    tileset_info_t info;
    sfTexture *texture;
    sfVector2u texture_size;
} tileset_t;

tileset_t *tileset_create(char const *file_path, tileset_info_t info);

tileset_t *tileset_register(game_t *game, char const *name,
char const *file_path, tileset_info_t info);

tileset_t *tileset_get(hashmap_t *tilesets, char const *name);

void tilesets_free(hashmap_t *tilesets);

sfIntRect get_tile(tileset_t *tileset, int tile_id, sfIntRect *original);

#endif