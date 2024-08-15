/*
** EPITECH PROJECT, 2021
** get_obj_sprite.c
** File description:
** Get object sprite
*/

#include <objects.h>

sfSprite *get_obj_sprite(obj_t *obj)
{
    if (obj == NULL)
        return (NULL);
    return (obj->sprite);
}