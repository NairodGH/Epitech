/*
** EPITECH PROJECT, 2021
** destroy_objects.c
** File description:
** Destroy game objects
*/

#include <objects.h>
#include <stdlib.h>

void destroy_objects(list_t *list)
{
    obj_t *obj;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        obj = (obj_t *) node->value;
        destroy_object(obj);
    }
}