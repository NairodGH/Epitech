/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init credits panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>
#include <file_utils.h>

void init_credits_text(engine_t *engine, panel_t *panel)
{
    char *text = read_file("config/credits.dat");
    sfFont *font = NULL;
    txt_t *txt;

    if (text == NULL)
        text = "";
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    txt = create_text(font, text, (sfVector2f) {0, 0});
    set_text_type(txt, TXT_CREDITS);
    set_text_size(txt, 28);
    center_text_xy(engine, txt);
    set_text_pos(txt, (sfVector2f) {txt->pos.x, txt->pos.y + 900});
    register_text(panel, txt);
}

void init_credits_menu(engine_t *eng, game_t *game, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    obj_t *b = create_object("assets/mcredits/bg.png", rct, pos);

    (void) game;
    register_object(panel, b);
    init_credits_text(eng, panel);
    set_panel_visibility(panel, true);
}

void init_panel_credits(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(CREDITS);
    set_panel_initializer(panel, &init_credits_menu, NULL);
    set_panel_events(panel, &credits_events);
    set_panel_updater(panel, NULL, &scroll_credits);

    (void) game;
    register_panel(eng, panel);
}