/*
** EPITECH PROJECT, 2021
** destroy_panel.c
** File description:
** Destroy a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <texts.h>
#include <stdlib.h>

void destroy_panel(panel_t *panel)
{
    if (panel == NULL)
        return;
    if (panel->objects != NULL) {
        destroy_objects(panel->objects);
        panel->objects = NULL;
    }
    if (panel->buttons != NULL) {
        destroy_buttons(panel->buttons);
        panel->buttons = NULL;
    }
    if (panel->texts != NULL) {
        destroy_texts(panel->texts);
        panel->texts = NULL;
    }
}