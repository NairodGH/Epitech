/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <panel.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

void register_object(panel_t *panel, obj_t *obj)
{
    if (panel == NULL || obj == NULL)
        return;
    if (panel->objects == NULL)
        panel->objects = list_create();
    list_add(panel->objects, obj);
}