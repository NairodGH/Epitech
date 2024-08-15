/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <objects.h>

PRIVATE void init_object_defaults(obj_t *obj)
{
    if (obj == NULL)
        return;
    obj->sprite = NULL;
    obj->texture = NULL;
    obj->shader = NULL;
    obj->render = (sfRenderStates){0};
    obj->clock = sfClock_create();
    obj->state = 0;
    obj->statef = 0.f;
    obj->tooltip = NULL;
    obj->color = (sfColor) {255, 255, 255, 255};
    obj->child = NULL;
    obj->on_click = NULL;
    set_obj_asset(obj, obj->asset);
    set_obj_visibility(obj, true);
    set_obj_type(obj, 0);
}

obj_t *create_object(char *asset, sfIntRect rect, sfVector2f pos)
{
    obj_t *obj;

    if (asset == NULL)
        return (NULL);
    obj = ncalloc(1, sizeof(obj_t));
    if (obj == NULL)
        return (NULL);
    obj->asset = asset;
    obj->rect = rect;
    obj->pos = pos;
    init_object_defaults(obj);
    return (obj->sprite != NULL && obj->texture != NULL ? obj : NULL);
}