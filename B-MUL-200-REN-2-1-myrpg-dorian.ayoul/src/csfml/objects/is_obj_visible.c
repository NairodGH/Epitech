/*
** EPITECH PROJECT, 2021
** is_obj_visible.c
** File description:
** Is object visible
*/

#include <objects.h>

bool is_obj_visible(obj_t *obj)
{
    if (obj == NULL)
        return (false);
    return (obj->visibility);
}