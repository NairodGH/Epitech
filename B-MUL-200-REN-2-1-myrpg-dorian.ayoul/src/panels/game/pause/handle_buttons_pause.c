/*
** EPITECH PROJECT, 2021
** handle buttons pause
** File description:
** handle buttons
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void on_pause_resume(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    gm->paused = false;
    hide_panel(eng, PAUSE);
}

void on_pause_options(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    gm->paused = false;
    hide_panel(eng, PAUSE);
    hide_panel(eng, GAME);
    hide_panel(eng, SNOW_PANEL);
    hide_panel(eng, RAIN_PANEL);
    hide_panel(eng, FOG_PANEL);
    hide_panel(eng, HUD);
    show_panel_by_id(eng, gm, SETTINGS);
    eng->last_panel = get_panel_by_id(eng, GAME);
}

void on_pause_start(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    gm->paused = false;
    hide_panel(eng, PAUSE);
    close_panel_by_id(eng, gm, GAME);
    close_panel_by_id(eng, gm, SNOW_PANEL);
    close_panel_by_id(eng, gm, RAIN_PANEL);
    close_panel_by_id(eng, gm, FOG_PANEL);
    hide_panel(eng, HUD);
    stage_free(gm);
    show_panel_by_id(eng, gm, START);
    gm->saves = load_saves(gm);
}

void on_pause_quit(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    (void) gm;
    gc_sounds(eng, true);
    destroy_engine(eng);
}