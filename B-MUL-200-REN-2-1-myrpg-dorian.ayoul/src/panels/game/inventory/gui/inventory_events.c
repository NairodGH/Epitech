/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Inventory events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void on_left_inventory(ENGPANEL, button_t *btn UNUSED)
{
    unsigned int current = get_current_page(panel);

    if (current <= 1) {
        play_seffect(game, engine, "assets/sounds/click-err.ogg");
        return;
    }
    navigate_inventory(panel, -1);
    play_seffect(game, engine, "assets/sounds/click-ok.ogg");
}

void on_right_inventory(ENGPANEL, button_t *btn UNUSED)
{
    unsigned int pages = get_inventory_pagecount(game);
    unsigned int current = get_current_page(panel);

    if (current == pages) {
        play_seffect(game, engine, "assets/sounds/click-err.ogg");
        return;
    }
    navigate_inventory(panel, 1);
    play_seffect(game, engine, "assets/sounds/click-ok.ogg");
}

void on_close_inventory(ENGPANEL, button_t *btn UNUSED)
{
    close_panel_by_id(engine, game, GAME_INVENTORY);
}