/*
** EPITECH PROJECT, 2021
** set_obj_shader.c
** File description:
** Set game object shader
*/

#include <objects.h>

void set_obj_renderstates(obj_t *obj)
{
    if (!obj || !obj->shader)
        return;
    obj->render = (sfRenderStates){
        .shader = obj->shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };
}
