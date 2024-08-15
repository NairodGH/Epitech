/*
** EPITECH PROJECT, 2021
** show_panel.c
** File description:
** Show a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <sounds.h>

PRIVATE void start_panel_sound(engine_t *engine UNUSED, panel_t *panel)
{
    if (!panel || !panel->bg_sound)
        return;
    play_sound(panel->bg_sound);
}

void show_panel(engine_t *engine, game_t *game, panel_t *panel)
{
    if (panel == NULL || is_panel_visible(panel))
        return;
    set_panel_visibility(panel, true);
    start_panel_sound(engine, panel);
    if (panel->init || panel->on_init == NULL)
        return;
    engine->panel_changed = true;
    panel->on_init(engine, game, panel);
    panel->init = true;
}