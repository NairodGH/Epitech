/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init buttons start
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_buttons_start_play(game_t *game, panel_t *panel)
{
    char *bpath = "assets/btns/start.png";
    sfIntRect rct2 = {0, 0, 147, 71};
    sfVector2f btnpos = {390, 234};
    button_t *btn = create_button(bpath, rct2, btnpos, true);
    obj_t *obj = create_shader("assets/shader/mainmenu.frag");
    float elap = 0.f;

    if (!obj)
        return;
    obj->texture = sfTexture_create(game->window->base_size.x,
                                    game->window->base_size.y);
    register_object(panel, obj);
    obj->child = &elap;
    set_obj_type(obj, OBJ_BG_STARTMENU);
    set_obj_visibility(obj, true);
    set_button_events(btn, &on_start_click);
    set_tooltip(btn, "Start the game");
    register_button(panel, btn);
    register_object(panel, obj);
}

void init_buttons_start_quit(panel_t *panel)
{
    char *bpath = "assets/btns/quit.png";
    sfIntRect rct = {0, 0, 90, 90};
    sfVector2f pos = {860, 5};
    button_t *btn = create_button(bpath, rct, pos, true);

    set_button_events(btn, &on_quit_click);
    set_tooltip(btn, "Quit the game");
    register_button(panel, btn);
}

void init_buttons_start_custom(panel_t *panel)
{
    char *bpath = "assets/btns/cusplayer.png";
    sfIntRect rct = {0, 0, 55, 56};
    sfVector2f pos = {395, 310};
    button_t *btn = create_button(bpath, rct, pos, true);

    set_button_events(btn, &on_cusmenu_click);
    set_tooltip(btn, "Customize character");
    register_button(panel, btn);
    bpath = "assets/btns/hwp.png";
    rct = (sfIntRect) {0, 0, 55, 56};
    pos = (sfVector2f) {470, 310};
    btn = create_button(bpath, rct, pos, true);
    set_button_events(btn, &on_hwp_click);
    set_tooltip(btn, "See game info");
    register_button(panel, btn);
}

void init_buttons_start_credits(panel_t *panel)
{
    char *bpath = "assets/btns/credits.png";
    sfIntRect rct = {0, 0, 55, 59};
    sfVector2f pos = {5, 5};
    button_t *btn = create_button(bpath, rct, pos, true);

    set_button_events(btn, &on_credits_click);
    set_tooltip(btn, "Game credits");
    register_button(panel, btn);
}

void init_buttons_start_settings(panel_t *panel)
{
    char *bpath = "assets/btns/settings.png";
    sfIntRect rct = {0, 0, 90, 90};
    sfVector2f pos = {860, 105};
    button_t *btn = create_button(bpath, rct, pos, true);

    set_button_events(btn, &on_settings_click);
    set_tooltip(btn, "Go to settings menu");
    register_button(panel, btn);
}