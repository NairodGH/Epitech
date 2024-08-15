/*
** EPITECH PROJECT, 2021
** is_obj_clicked.c
** File description:
** Is game object clicked?
*/

#include <objects.h>
#include <cmath.h>

bool is_obj_clicked(obj_t *obj, sfVector2i ev)
{
    sfIntRect rect;
    sfVector2f from;
    sfVector2f to;

    if (obj == NULL || !obj->sprite)
        return (false);
    rect = obj->rect;
    from = sfSprite_getPosition(obj->sprite);
    to = (sfVector2f){obj->pos.x + rect.width, obj->pos.y + rect.height};
    return is_in_square(from, to, (sfVector2f){ev.x, ev.y});
}