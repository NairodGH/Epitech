/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init panel buttons
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_save_quit(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    hide_panel(eng, SETTINGS);
    if (eng->last_panel != NULL) {
        show_panel_by_id(eng, gm, eng->last_panel->id);
        if (eng->last_panel->id == GAME) {
            show_panel_by_id(eng, gm, HUD);
            show_panel_by_id(eng, gm, SNOW_PANEL);
            show_panel_by_id(eng, gm, RAIN_PANEL);
            show_panel_by_id(eng, gm, FOG_PANEL);
        }
    }else{
        show_panel_by_id(eng, gm, START);
    }
}

PRIVATE void init_panel_button_save(panel_t *panel)
{
    char *save_btn = "assets/msettings/save_btn.png";
    sfIntRect rct = {0, 0, 147, 71};
    sfVector2f pos = {406, 460};
    button_t *btn = create_button(save_btn, rct, pos, true);

    set_button_events(btn, &on_save_quit);
    set_tooltip(btn, "Save the current settings");
    register_button(panel, btn);
}

PRIVATE void init_panel_buttons_volume(panel_t *panel)
{
    char *left_btn = "assets/btns/arrow_left.png";
    char *right_btn = "assets/btns/arrow_right.png";
    sfIntRect rct = {0, 0, 32, 41};
    sfVector2f pos = {487, 184};
    button_t *btn = create_button(left_btn, rct, pos, true);

    set_button_events(btn, &on_volume_decrease);
    set_tooltip(btn, "Decrease the volume");
    register_button(panel, btn);
    pos = (sfVector2f) {585, 184};
    btn = create_button(right_btn, rct, pos, true);
    set_button_events(btn, &on_volume_increase);
    set_tooltip(btn, "Increase the volume");
    register_button(panel, btn);
}

PRIVATE void init_panel_buttons_fps(panel_t *panel)
{
    char *left_btn = "assets/btns/arrow_left.png";
    char *right_btn = "assets/btns/arrow_right.png";
    sfIntRect rct = {0, 0, 32, 41};
    sfVector2f pos = {487, 228};
    button_t *btn = create_button(left_btn, rct, pos, true);

    set_button_events(btn, &on_fps_decrease);
    set_tooltip(btn, "Decrease the framerate");
    register_button(panel, btn);
    pos = (sfVector2f) {585, 228};
    btn = create_button(right_btn, rct, pos, true);
    set_button_events(btn, &on_fps_increase);
    set_tooltip(btn, "Increase the framerate");
    register_button(panel, btn);
}

void init_panel_buttons(panel_t *panel)
{
    init_panel_button_save(panel);
    init_panel_buttons_volume(panel);
    init_panel_buttons_fps(panel);
}