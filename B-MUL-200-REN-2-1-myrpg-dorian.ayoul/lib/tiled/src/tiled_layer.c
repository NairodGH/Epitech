/*
** EPITECH PROJECT, 2021
** rpg - tiled
** File description:
** tiled/layer
*/

#include <tiled.h>

int tiled_parse_layers(tiled_map_t *map, char const *xml)
{
    char **layer_balises = xml_get_balises(xml, "layer");
    char *name;
    char *data;

    if (layer_balises == NULL)
        return 1;
    map->layers = hashmap_create();
    for (int i = 0; layer_balises[i]; i++) {
        name = xml_get_attribute(layer_balises[i], "name");
        data = xml_get_content(xml_get_balise(layer_balises[i], "data"));
        if (data == NULL) {
            free(layer_balises);
            return 1;
        }
        hashmap_add(map->layers, name, data);
    }
    free(layer_balises);
    return 0;
}