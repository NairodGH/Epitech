/*
** EPITECH PROJECT, 2021
** set_panel_events.c
** File description:
** Set panel events
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void set_panel_events(panel_t *panel, void (*ev)(ENGPANEL, sfEvent event))
{
    if (panel == NULL)
        return;
    panel->on_event = ev;
}