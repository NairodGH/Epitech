/*
** EPITECH PROJECT, 2021
** set_obj_events.c
** File description:
** Set object events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>

void set_obj_events(obj_t *obj, void (*ev)(ENGPANEL, obj_t *obj))
{
    if (obj == NULL)
        return;
    obj->on_click = ev;
}