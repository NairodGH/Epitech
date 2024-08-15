/*
** EPITECH PROJECT, 2021
** set_obj_asset.c
** File description:
** Set a game object asset
*/

#include <objects.h>

void set_obj_shader(obj_t *obj, char *asset)
{
    if (obj == NULL || asset == NULL)
        return;
    obj->sprite = sfSprite_create();
    obj->shader = sfShader_createFromFile(NULL, NULL, obj->asset);
    if (!obj->sprite || !obj->shader)
        return;
    sfSprite_setColor(obj->sprite, sfTransparent);
    obj->render = (sfRenderStates) {
        .shader = obj->shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };
}