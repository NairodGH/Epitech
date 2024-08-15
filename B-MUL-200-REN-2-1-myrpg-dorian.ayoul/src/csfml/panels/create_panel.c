/*
** EPITECH PROJECT, 2021
** create_panel.c
** File description:
** Create a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

panel_t *create_panel(int id)
{
    panel_t *panel = ncalloc(1, sizeof(panel_t));

    if (panel == NULL)
        return (NULL);
    panel->id = id;
    panel->objects = NULL;
    panel->buttons = NULL;
    panel->tooltips = NULL;
    panel->texts = NULL;
    panel->init = false;
    panel->bg_sound = NULL;
    set_panel_initializer(panel, NULL, NULL);
    set_panel_updater(panel, NULL, NULL);
    set_panel_events(panel, NULL);
    set_panel_visibility(panel, false);
    return (panel);
}