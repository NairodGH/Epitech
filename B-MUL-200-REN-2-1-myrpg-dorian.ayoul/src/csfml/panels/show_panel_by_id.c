/*
** EPITECH PROJECT, 2021
** show_panel_by_id.c
** File description:
** Show panel by id
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void show_panel_by_id(engine_t *engine, game_t *game, int id)
{
    panel_t *panel;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (panel->id != id)
            continue;
        show_panel(engine, game, panel);
    }
}