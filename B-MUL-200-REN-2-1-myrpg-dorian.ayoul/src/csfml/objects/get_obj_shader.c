/*
** EPITECH PROJECT, 2021
** get_obj_shader.c
** File description:
** Get object rect
*/

#include <objects.h>

sfShader *get_obj_shader(obj_t *obj)
{
    if (!obj)
        return NULL;
    return obj->shader;
}
