/*
** EPITECH PROJECT, 2021
** get_obj_renderstates.c
** File description:
** Get object renderstates
*/

#include <objects.h>

sfrenderstate_t get_obj_renderstates(obj_t *obj)
{
    if (!obj)
        return (sfRenderStates){0};
    return obj->render;
}
