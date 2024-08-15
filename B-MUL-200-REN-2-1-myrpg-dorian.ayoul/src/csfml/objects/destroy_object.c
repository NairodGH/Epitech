/*
** EPITECH PROJECT, 2021
** destroy_object.c
** File description:
** Destroy a game object
*/

#include <objects.h>
#include <stdlib.h>

PRIVATE void destroy_tooltip(obj_t *obj)
{
    if (obj->tooltip != NULL && obj->tooltip->sprite) {
        sfSprite_destroy(obj->tooltip->sprite);
        obj->tooltip->sprite = NULL;
        free(obj->tooltip);
    }
}

void destroy_object(obj_t *obj)
{
    if (obj == NULL || !obj->sprite)
        return;
    if (obj->sprite != NULL) {
        sfSprite_destroy(obj->sprite);
        obj->sprite = NULL;
    }
    if (obj->texture != NULL) {
        sfTexture_destroy(obj->texture);
        obj->texture = NULL;
    }
    destroy_tooltip(obj);
    if (obj->shader != NULL) {
        sfShader_destroy(obj->shader);
        obj->shader = NULL;
    }
}