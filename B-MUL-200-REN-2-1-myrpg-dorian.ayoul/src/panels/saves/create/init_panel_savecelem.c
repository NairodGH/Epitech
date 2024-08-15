/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save list panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_save_text(panel_t *panel)
{
    sfFont *font;
    txt_t *txt;
    sfVector2f pos = {351, 276};

    if (panel == NULL)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (font == NULL)
        return;
    txt = create_text(font, "", pos);
    set_text_size(txt, 22);
    set_text_color(txt, sfBlack);
    set_text_type(txt, TXT_SAVE_CREATE_NAME);
    register_text(panel, txt);
}

void init_buttons_save_save(panel_t *panel)
{
    sfIntRect rct = {0, 0, 140, 69};
    char *asset = "assets/btns/create.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){407, 435}, true);

    set_button_id(btn, BTN_SAVE_CREATE);
    set_button_events(btn, &on_save_save);
    set_tooltip(btn, "Create a save");
    register_button(panel, btn);
}

void init_savecreate_arrow(ENGPANEL)
{
    char *save_bg = "assets/msavecreate/arrow.png";
    sfIntRect rc = {0, 0, 32, 27};
    obj_t *b = create_object(save_bg, rc, (sfVector2f){340, 305});

    set_obj_type(b, OBJ_SAVECREATE_ARROW);
    register_object(panel, b);
}

void init_savecreate_menu(ENGPANEL)
{
    char *save_bg = "assets/msavecreate/bg.png";
    sfIntRect rc = {0, 0, 960, 540};
    obj_t *b = create_object(save_bg, rc, (sfVector2f){0, 0});

    register_object(panel, b);
    init_buttons_save_save(panel);
    init_savecreate_arrow(engine, game, panel);
    init_save_text(panel);
    set_panel_visibility(panel, true);
}