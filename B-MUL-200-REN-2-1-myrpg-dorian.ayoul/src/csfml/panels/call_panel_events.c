/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>

void call_panel_events(engine_t *engine, game_t *game, sfEvent event)
{
    panel_t *panel;

    if (engine == NULL || engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        if (!is_panel_visible(panel))
            continue;
        if (panel->on_event == NULL)
            continue;
        panel->on_event(engine, game, panel, event);
    }
}