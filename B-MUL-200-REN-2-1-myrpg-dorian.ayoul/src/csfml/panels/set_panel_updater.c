/*
** EPITECH PROJECT, 2021
** set_panel_updater.c
** File description:
** Set panel updater
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void set_panel_updater(panel_t *panel, void (*on_tick_update)(ENGPANEL), \
    void (*on_render_update)(ENGPANEL))
{
    if (panel == NULL)
        return;
    panel->on_tick_update = on_tick_update;
    panel->on_render_update = on_render_update;
}