/*
** EPITECH PROJECT, 2021
** get_obj_color.c
** File description:
** Get object color
*/

#include <objects.h>

sfColor get_obj_color(obj_t *obj)
{
    if (obj == NULL)
        return (sfBlack);
    return (obj->color);
}