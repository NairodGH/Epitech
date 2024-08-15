/*
** EPITECH PROJECT, 2021
** set_obj_pos.c
** File description:
** Set game object position
*/

#include <objects.h>

void set_obj_pos(obj_t *obj, sfVector2f pos)
{
    if (obj == NULL || obj->sprite == NULL)
        return;
    sfSprite_setPosition(obj->sprite, pos);
}