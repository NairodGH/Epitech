/*
** EPITECH PROJECT, 2021
** set_obj_visibility.c
** File description:
** Set game object visibility
*/

#include <objects.h>

void set_obj_visibility(obj_t *obj, bool visibility)
{
    if (obj == NULL)
        return;
    obj->visibility = visibility;
}