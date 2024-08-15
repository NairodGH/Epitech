/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled
*/

#ifndef _TILED_H
#define _TILED_H

#include <hnep/config/nxml.h>
#include <nep/nstring.h>
#include <nep/nlist.h>
#include <nep/nhashmap.h>
#include <nep/nmem.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int firstgid;
} tiled_tileset_t;

typedef struct {
    int width;
    int height;
    list_t *tilesets;
    hashmap_t *layers;
} tiled_map_t;

tiled_map_t *tiled_parse(char const *path);

int tiled_parse_tilesets(tiled_map_t *map, char const *xml);
int tiled_parse_layers(tiled_map_t *map, char const *xml);

#endif