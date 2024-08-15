/*
** EPITECH PROJECT, 2021
** get_obj_asset.c
** File description:
** Get object asset
*/

#include <objects.h>

char *get_obj_asset(obj_t *obj)
{
    if (obj == NULL)
        return (NULL);
    return (obj->asset);
}