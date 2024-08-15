/*
** EPITECH PROJECT, 2021
** get_obj_texture.c
** File description:
** Get object texture
*/

#include <objects.h>

sfTexture *get_obj_texture(obj_t *obj)
{
    if (obj == NULL)
        return (NULL);
    return (obj->texture);
}