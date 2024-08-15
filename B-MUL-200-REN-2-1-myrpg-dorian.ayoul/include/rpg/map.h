/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** map
*/

#ifndef RPG_MAP_H
#define RPG_MAP_H

#include <rpg/tiled.h>

#include <nep/nctype.h>
#include <nep/nlist.h>
#include <SFML/Graphics.h>

typedef struct tileset_s tileset_t;
typedef struct grid_s grid_t;

typedef struct pos_s {
    double x;
    double y;
} pos_t;

typedef struct posint_s {
    int x;
    int y;
} posint_t;

typedef struct map_tile_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    char *tileset_id;
    int tile_id;
} map_tile_t;

typedef struct map_s {
    sfVector2f size;
    grid_t *grid;
    pos_t sroll;
    map_tile_t **fondation;
    map_tile_t **houses;
    map_tile_t **objects;
    map_tile_t **props1;
    map_tile_t **props2;
    map_tile_t **trees1;
    map_tile_t **trees2;
    map_tile_t **trees3;
    map_tile_t **info;
    sfVector2f active_item_pos;
    sfVector2f active_tile_pos;
} map_t;

map_t *map_create(int width, int height);

void map_fill(map_t *map, tiled_map_t *tiled_map, hashmap_t *tilesets);

void map_free(map_t *map);

map_tile_t **layer_create(sfVector2f size);

void layer_fill(map_tile_t **layer, sfVector2f size, char *tiled_layer, \
list_t *tilesets);

void layer_set(map_tile_t **layer, sfVector2f size, hashmap_t *tilesets);

void layer_free(map_tile_t **layer, sfVector2f size);

#endif