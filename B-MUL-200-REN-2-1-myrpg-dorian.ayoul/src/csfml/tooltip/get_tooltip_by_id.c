/*
** EPITECH PROJECT, 2021
** get_tooltip_by_id.c
** File description:
** get tooltip by id
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <stdlib.h>
#include <texts.h>

tooltip_t *get_tooltip_by_id(panel_t *panel, int id)
{
    tooltip_t *tlp = NULL;

    if (panel == NULL || panel->tooltips == NULL)
        return (tlp);
    list_foreach(panel->tooltips, node) {
        tlp = (tooltip_t *) node->value;
        if (tlp->id == id)
            return (tlp);
    }
    return (NULL);
}