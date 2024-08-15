/*
** EPITECH PROJECT, 2021
** duplicate_object.c
** File description:
** Duplicate a game object
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <objects.h>

obj_t *duplicate_object(obj_t *obj)
{
    if (obj == NULL)
        return (NULL);
    if (obj->sprite == NULL)
        return (NULL);
    return (create_object(obj->asset, obj->rect, obj->pos));
}