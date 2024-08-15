/*
** EPITECH PROJECT, 2021
** hide_panel.c
** File description:
** Hide a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <sounds.h>

PRIVATE void pause_panel_sound(panel_t *panel)
{
    if (!panel || !panel->bg_sound)
        return;
    pause_sound(panel->bg_sound);
}

void hide_panel(engine_t *engine, int id)
{
    panel_t *panel;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (panel->id != id)
            continue;
        set_panel_visibility(panel, false);
        pause_panel_sound(panel);
    }
}