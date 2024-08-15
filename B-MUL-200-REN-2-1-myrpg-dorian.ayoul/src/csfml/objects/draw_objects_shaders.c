/*
** EPITECH PROJECT, 2021
** draw_objects_shaders.c
** File description:
** Draw game objects with shaders
*/

#include <panel.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void draw_objects_shaders(engine_t *engine, list_t *list)
{
    obj_t *obj;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        obj = (obj_t *) node->value;
        draw_object_shader(engine, obj);
    }
}
