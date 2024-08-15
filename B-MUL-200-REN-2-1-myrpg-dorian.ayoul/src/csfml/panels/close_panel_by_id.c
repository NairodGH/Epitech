/*
** EPITECH PROJECT, 2021
** close_panel_by_id.c
** File description:
** Close panel by id
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void close_panel_by_id(engine_t *engine, game_t *game, int id)
{
    panel_t *panel;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (panel->id != id)
            continue;
        close_panel(engine, game, panel);
    }
}