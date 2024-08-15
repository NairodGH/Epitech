/*
** EPITECH PROJECT, 2021
** draw_panels.c
** File description:
** Draw panels
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <texts.h>

void draw_panels(engine_t *engine, game_t *game)
{
    panel_t *panel;

    if (engine->panels == NULL)
        return;
    list_foreach(engine->panels, node) {
        panel = (panel_t *) node->value;
        draw_panel(engine, game, panel);
    }
}