/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled/test
*/

#include <tiled.h>
#include <nep/nprintf.h>

PRIVATE void display_map(tiled_map_t *map)
{
    tiled_tileset_t *tileset;
    char *data_props;

    nprintf("=== Map info ===\n");
    nprintf("width=%i\n", map->width);
    nprintf("height=%i\n", map->height);
    nprintf("tilesets:\n");
    list_foreach(map->tilesets, node) {
        tileset = (tiled_tileset_t *)node->value;
        nprintf("- tileset[name: \"%s\", firstgid=%i]\n", tileset->name, \
        tileset->firstgid);
    }
    data_props = (char *)hashmap_get_value(map->layers, "Props");
    nprintf("Layer 'Props' :\n%s", data_props);
}

int main(int argc, char const *argv[])
{
    tiled_map_t *map;

    if (argc != 2)
        return 84;
    map = tiled_parse(argv[1]);
    if (map == NULL) {
        nfprintf(stderr, "Invalid map!\n");
        return 84;
    }
    display_map(map);
    return 0;
}
