/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle custom player menu buttons
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_cusplayer_select(ENGPANEL, button_t *btn)
{
    if (game == NULL || btn == NULL)
        return;
    if (game->settings == NULL)
        return;
    game->settings->player = btn->id - BTN_CUSPLAYER_SELECTOR_1 + 1;
    save_settings(game->settings);
}

void on_cusplayer_save(ENGPANEL, button_t *btn)
{
    (void) btn;
    hide_panel(engine, CUSTOM_PLAYER);
    show_panel_by_id(engine, game, START);
}