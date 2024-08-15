/*
** EPITECH PROJECT, 2021
** get_obj_type.c
** File description:
** Get object type
*/

#include <objects.h>

int get_obj_type(obj_t *obj)
{
    if (obj == NULL)
        return (-1);
    return (obj->type);
}