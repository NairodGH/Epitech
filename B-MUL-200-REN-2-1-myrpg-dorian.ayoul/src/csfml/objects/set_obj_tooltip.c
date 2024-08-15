/*
** EPITECH PROJECT, 2021
** set_obj_tooltip.c
** File description:
** Set object tooltip
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <stdlib.h>
#include <texts.h>

void set_obj_tooltip(obj_t *obj, char *text)
{
    tooltip_t *tooltip;

    if (obj == NULL || text == NULL)
        return;
    tooltip = create_tooltip(text);
    obj->tooltip = tooltip;
}