/*
** EPITECH PROJECT, 2021
** get_obj_center.c
** File description:
** Get an object center
*/

#include <engine.h>
#include <objects.h>

sfVector2f get_obj_center(obj_t *obj)
{
    sfVector2f res = {0, 0};
    sfIntRect rect;

    if (obj == NULL)
        return (res);
    res = obj->pos;
    rect = obj->rect;
    res.x += rect.width / 2;
    res.y += rect.height / 2;
    return (res);
}