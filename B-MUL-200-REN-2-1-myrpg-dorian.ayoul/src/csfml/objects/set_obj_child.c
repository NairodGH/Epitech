/*
** EPITECH PROJECT, 2021
** set_obj_asset.c
** File description:
** Set a game object child
*/

#include <objects.h>

void set_obj_child(obj_t *obj, void *child)
{
    if (!obj)
        return;
    obj->child = child;
}