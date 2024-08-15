/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init end panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_end_home(ENGPANEL, button_t *button)
{
    (void) button;
    show_panel_by_id(engine, game, START);
    close_panel_by_id(engine, game, GAME_END);
}

void init_buttons_home(panel_t *panel)
{
    sfIntRect rct = {0, 0, 149, 69};
    char *asset = "assets/end/home.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){308, 465}, true);

    set_button_id(btn, BTN_END_HOME);
    set_button_events(btn, &on_end_home);
    set_tooltip(btn, "Go to title screen");
    register_button(panel, btn);
}