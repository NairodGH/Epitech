/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init end credits button
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_end_credits(ENGPANEL, button_t *button)
{
    (void) button;
    show_panel_by_id(engine, game, CREDITS);
    close_panel_by_id(engine, game, GAME_END);
}

void init_buttons_credits(panel_t *panel)
{
    sfIntRect rct = {0, 0, 149, 69};
    char *asset = "assets/end/credits.png";
    button_t *btn = create_button(asset, rct, (sfVector2f){500, 465}, true);

    set_button_id(btn, BTN_END_CREDITS);
    set_button_events(btn, &on_end_credits);
    set_tooltip(btn, "See game credits");
    register_button(panel, btn);
}