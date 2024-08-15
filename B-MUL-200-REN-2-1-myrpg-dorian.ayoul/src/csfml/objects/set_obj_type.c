/*
** EPITECH PROJECT, 2021
** set_obj_type.c
** File description:
** Set game object type
*/

#include <objects.h>

void set_obj_type(obj_t *obj, int type)
{
    if (obj == NULL)
        return;
    obj->type = type;
}