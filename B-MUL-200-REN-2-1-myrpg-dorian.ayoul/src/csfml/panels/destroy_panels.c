/*
** EPITECH PROJECT, 2021
** destroy_panels.c
** File description:
** Destroy panels
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void destroy_panels(list_t *list)
{
    panel_t *panel;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        panel = (panel_t *) node->value;
        destroy_panel(panel);
    }
    list_free(list);
}