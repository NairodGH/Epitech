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
#include <texts.h>
#include <sounds.h>
#include <rpg/rpg.h>

void on_exityes(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) gm;
    (void) pan;
    (void) btn;
    destroy_engine(eng);
}

void on_exitno(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    panel_t *last = eng->last_panel;

    (void) pan;
    (void) btn;
    if (last != NULL)
        show_panel(eng, gm, last);
    else
        show_panel_by_id(eng, gm, START);
    hide_panel(eng, EXIT_CONFIRMATION);
    eng->last_panel = last;
}

void init_buttons_exit_yes(panel_t *panel)
{
    char *bpath = "assets/btns/yes.png";
    sfIntRect rct2 = {0, 0, 147, 71};
    sfVector2f btnpos = {280, 334};
    button_t *btn = create_button(bpath, rct2, btnpos, true);

    set_button_events(btn, &on_exityes);
    set_tooltip(btn, "Exit game");
    register_button(panel, btn);
}

void init_buttons_exit_no(panel_t *panel)
{
    char *bpath = "assets/btns/no.png";
    sfIntRect rct2 = {0, 0, 147, 71};
    sfVector2f btnpos = {500, 334};
    button_t *btn = create_button(bpath, rct2, btnpos, true);

    set_button_events(btn, &on_exitno);
    set_tooltip(btn, "Cancel");
    register_button(panel, btn);
}

void init_exit_text(panel_t *panel)
{
    sfFont *font;
    txt_t *txt;
    sfVector2f pos = {215, 250};

    if (panel == NULL)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (font == NULL)
        return;
    txt = create_text(font, "Do you really want to quit the game?", pos);
    set_text_size(txt, 30);
    set_text_color(txt, sfWhite);
    register_text(panel, txt);
}