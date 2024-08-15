/*
** EPITECH PROJECT, 2021
** set_obj_rect.c
** File description:
** Set game object rect
*/

#include <objects.h>

void set_obj_rect(obj_t *obj, sfIntRect rect)
{
    if (obj == NULL || obj->sprite == NULL)
        return;
    sfSprite_setTextureRect(obj->sprite, rect);
}