/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <rpg/rpg.h>

obj_t *get_player(panel_t *pan)
{
    obj_t *obj = NULL;

    if (pan == NULL || pan->objects == NULL)
        return (NULL);
    list_foreach(pan->objects, node) {
        obj = (obj_t *) node->value;
        if (obj == NULL)
            continue;
        if (obj->type != OBJ_PLAYER)
            continue;
        return (obj);
    }
    return (NULL);
}