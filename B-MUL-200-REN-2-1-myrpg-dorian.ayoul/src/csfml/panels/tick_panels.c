/*
** EPITECH PROJECT, 2021
** tick_panels.c
** File description:
** Tick panels
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <texts.h>

void tick_panels(engine_t *engine, game_t *game)
{
    panel_t *panel;

    if (engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!panel->visibility)
            continue;
        if (panel->on_tick_update != NULL)
            panel->on_tick_update(engine, game, panel);
    }
}