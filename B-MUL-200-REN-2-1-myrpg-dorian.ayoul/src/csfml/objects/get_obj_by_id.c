/*
** EPITECH PROJECT, 2021
** get_obj_by_id.c
** File description:
** Get object by id
*/

#include <engine.h>
#include <objects.h>
#include <panel.h>

obj_t *get_obj_by_id(panel_t *panel, int id)
{
    obj_t *obj = NULL;

    if (panel == NULL || panel->objects == NULL)
        return (obj);
    list_foreach(panel->objects, node) {
        obj = (obj_t *) node->value;
        if (obj->type == id)
            return (obj);
    }
    return (NULL);
}