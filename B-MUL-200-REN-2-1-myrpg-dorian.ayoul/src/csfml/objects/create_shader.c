/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <objects.h>

PRIVATE void init_shader_defaults(obj_t *obj)
{
    if (obj == NULL)
        return;
    obj->sprite = NULL;
    obj->texture = NULL;
    obj->shader = NULL;
    obj->pos = (sfVector2f){0};
    obj->render = (sfRenderStates){0};
    obj->rect = (sfIntRect){0};
    obj->clock = sfClock_create();
    set_obj_shader(obj, obj->asset);
    set_obj_visibility(obj, true);
    set_obj_type(obj, 0);
}

obj_t *create_shader(char *asset)
{
    obj_t *obj;

    if (asset == NULL)
        return (NULL);
    obj = ncalloc(1, sizeof(obj_t));
    if (obj == NULL)
        return (NULL);
    obj->asset = asset;
    init_shader_defaults(obj);
    return (obj->shader != NULL && obj->sprite != NULL ? obj : NULL);
}