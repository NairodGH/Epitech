/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** tileset_get
*/

#include <rpg/rpg.h>

tileset_t *tileset_get(hashmap_t *tilesets, char const *name)
{
    if (tilesets == NULL || name == NULL)
        return NULL;
    return ((tileset_t *)hashmap_get_value(tilesets, name));
}