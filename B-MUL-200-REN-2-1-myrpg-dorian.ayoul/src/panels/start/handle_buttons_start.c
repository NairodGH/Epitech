/*
** EPITECH PROJECT, 2021
** handle buttons start
** File description:
** handle buttons
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_cusmenu_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, START);
    show_panel_by_id(eng, gm, CUSTOM_PLAYER);
}

void on_hwp_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, START);
    show_panel_by_id(eng, gm, HOW_TO_PLAY);
}

void on_start_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, START);
    show_panel_by_id(eng, gm, SAVE_LIST);
}

void on_quit_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, START);
    show_panel_by_id(eng, gm, EXIT_CONFIRMATION);
}

void on_settings_click(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    hide_panel(eng, START);
    show_panel_by_id(eng, gm, SETTINGS);
    eng->last_panel = get_panel_by_id(eng, START);
}