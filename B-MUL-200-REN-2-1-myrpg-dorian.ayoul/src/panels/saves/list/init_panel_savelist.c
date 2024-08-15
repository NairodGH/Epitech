/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save list panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_save_name(panel_t *panel, save_t *save, int x, int y)
{
    sfIntRect rct = {0, 0, 140, 69};
    char *asset = "assets/btns/savename.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){x, y}, true);
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    char *clear_name = get_pretty_save_name(save->name);
    txt_t *txt = create_text(font, clear_name, (sfVector2f){x + 20, y + 20});

    if (font == NULL)
        return;
    set_text_size(txt, nstrlen(clear_name) > 10 ? 10 : 20);
    set_text_color(txt, sfWhite);
    set_text_type(txt, TXT_SAVE_NAME);
    set_button_id(btn, BTN_SAVE_LOAD);
    set_button_events(btn, &on_save_load);
    set_tooltip(btn, "Load this save");
    register_button(panel, btn);
    register_text(panel, txt);
}

void init_buttons_save_create(game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 140, 69};
    char *asset = "assets/btns/create.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){395, 467}, 1);

    set_button_events(btn, &on_save_create);
    set_button_id(btn, BTN_SAVE_LISTCREATE);
    if (get_current_save_count(game) >= 9)
        set_tooltip(btn, "Too many saves");
    else
        set_tooltip(btn, "Create a new save");
    register_button(panel, btn);
}

void init_savelist_menu(ENGPANEL)
{
    char *save_bg = "assets/msavelist/bg.png";
    sfIntRect rc = {0, 0, 960, 540};
    obj_t *b = create_object(save_bg, rc, (sfVector2f){0, 0});

    register_object(panel, b);
    init_buttons_saves(game, panel);
    init_buttons_save_create(game, panel);
    set_panel_visibility(panel, true);
}

void init_panel_savelist(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(SAVE_LIST);
    set_panel_initializer(panel, &init_savelist_menu, NULL);
    set_panel_updater(panel, NULL, &render_savelist);

    (void) game;
    register_panel(eng, panel);
}