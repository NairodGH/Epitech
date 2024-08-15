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

void on_hwp_back(engine_t *eng, game_t *gm, panel_t *pan, button_t *btn)
{
    (void) pan;
    (void) btn;
    close_panel_by_id(eng, gm, HOW_TO_PLAY);
    show_panel_by_id(eng, gm, START);
}

void init_buttons_hwp_back(panel_t *panel)
{
    char *bpath = "assets/pause/title_screen.png";
    sfIntRect rct2 = {0, 0, 115, 57};
    sfVector2f btnpos = {410, 450};
    button_t *btn = create_button(bpath, rct2, btnpos, true);

    set_button_events(btn, &on_hwp_back);
    set_tooltip(btn, "Back to title screen");
    register_button(panel, btn);
}