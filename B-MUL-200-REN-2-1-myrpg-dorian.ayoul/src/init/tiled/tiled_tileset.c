/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled/tileset
*/

#include <rpg/tiled.h>

PRIVATE tiled_tileset_t *tiled_parse_tileset(char const *balise)
{
    tiled_tileset_t *tileset = ncalloc(1, sizeof(tiled_tileset_t));
    char *firstgid;
    char *source;

    if ((firstgid = xml_get_attribute(balise, "firstgid")) == NULL) {
        free(tileset);
        return NULL;
    }
    if ((source = xml_get_attribute(balise, "source")) == NULL) {
        free(tileset);
        return NULL;
    }
    tileset->name = source;
    tileset->firstgid = natoi(firstgid);
    free(firstgid);
    return tileset;
}

int tiled_parse_tilesets(tiled_map_t *map, char const *xml)
{
    char **tileset_balises = xml_get_balises(xml, "tileset");
    tiled_tileset_t *tileset;

    if (tileset_balises == NULL)
        return 1;
    map->tilesets = list_create();
    for (int i = 0; tileset_balises[i]; i++) {
        tileset = tiled_parse_tileset(tileset_balises[i]);
        if (tileset == NULL) {
            free(tileset_balises);
            return 1;
        }
        list_add(map->tilesets, tileset);
    }
    free(tileset_balises);
    return 0;
}