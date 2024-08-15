/*
** EPITECH PROJECT, 2021
** set_obj_asset.c
** File description:
** Set a game object asset
*/

#include <objects.h>

void set_obj_asset(obj_t *obj, char *asset)
{
    if (obj == NULL || asset == NULL)
        return;
    obj->asset = asset;
    obj->texture = sfTexture_createFromFile(asset, NULL);
    if (!obj->texture) {
        obj->texture = NULL;
        obj->sprite = NULL;
        return;
    }
    obj->sprite = sfSprite_create();
    if (!obj->sprite)
        return;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    set_obj_pos(obj, obj->pos);
    set_obj_rect(obj, obj->rect);
}