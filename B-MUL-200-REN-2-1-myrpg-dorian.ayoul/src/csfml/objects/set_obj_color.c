/*
** EPITECH PROJECT, 2021
** set_obj_color.c
** File description:
** Set object color
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>

void set_obj_color(obj_t *obj, sfColor color)
{
    if (obj == NULL)
        return;
    obj->color = color;
    sfSprite_setColor(obj->sprite, obj->color);
}