/*
** EPITECH PROJECT, 2021
** get_obj_pos.c
** File description:
** Get object position
*/

#include <objects.h>

sfVector2f get_obj_pos(obj_t *obj)
{
    if (obj == NULL)
        return ((sfVector2f) {0, 0});
    return (obj->pos);
}