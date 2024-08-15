/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init game panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void game_start_panel(ENGPANEL)
{
    load_game(engine, game, panel);
}

void on_game_quit(ENGPANEL)
{
    if (!panel)
        return;
    if (panel->bg_sound)
        stop_sound(panel->bg_sound);
    panel->bg_sound = NULL;
}

void init_panel_game(engine_t *eng, game_t *game UNUSED)
{
    panel_t *panel = create_panel(GAME);
    set_panel_initializer(panel, &game_start_panel, &on_game_quit);
    set_panel_events(panel, &game_event);
    set_panel_updater(panel, &game_tick, &game_render);

    register_panel(eng, panel);
}