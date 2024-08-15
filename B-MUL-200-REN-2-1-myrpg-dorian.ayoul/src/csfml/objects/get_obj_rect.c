/*
** EPITECH PROJECT, 2021
** get_obj_rect.c
** File description:
** Get object rect
*/

#include <objects.h>

sfIntRect get_obj_rect(obj_t *obj)
{
    if (obj == NULL)
        return ((sfIntRect) {0, 0, 0, 0});
    return (obj->rect);
}