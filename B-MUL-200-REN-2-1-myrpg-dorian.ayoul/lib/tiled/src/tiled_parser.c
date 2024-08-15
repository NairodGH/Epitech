/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled
*/

#include <tiled.h>
#include <file_utils.h>

PRIVATE int parse_map_info(tiled_map_t *map, char const *xml)
{
    char *map_balise = xml_get_balise(xml, "map");
    char *width;
    char *height;

    if (map == NULL || map_balise == NULL)
        return 1;
    if ((width = xml_get_attribute(map_balise, "width")) == NULL)
        return 1;
    if ((height = xml_get_attribute(map_balise, "height")) == NULL)
        return 1;
    map->width = natoi(width);
    map->height = natoi(height);
    free(width);
    free(height);
    return 0;
}

PRIVATE void free_on_error(char *xml, tiled_map_t *map)
{
    free(xml);
    free(map);
}

tiled_map_t *tiled_parse(char const *path)
{
    char *xml = read_file(path);
    tiled_map_t *map;

    if (xml == NULL)
        return NULL;
    map = ncalloc(1, sizeof(tiled_map_t));
    if (parse_map_info(map, xml)) {
        free_on_error(xml, map);
        return NULL;
    }
    if (tiled_parse_tilesets(map, xml)) {
        free_on_error(xml, map);
        return NULL;
    }
    if (tiled_parse_layers(map, xml)) {
        free_on_error(xml, map);
        return NULL;
    }
    free(xml);
    return map;
}