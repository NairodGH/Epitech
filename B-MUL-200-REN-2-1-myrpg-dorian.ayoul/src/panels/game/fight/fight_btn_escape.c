/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle escape fight button
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void on_fight_escape(ENGPANEL, button_t *btn)
{
    (void) btn;
    end_fight(engine, game);
}

void create_fight_escape_button(panel_t *panel)
{
    char *bpath = "assets/fight/escape.png";
    sfIntRect rct2 = {0, 0, 140, 69};
    sfVector2f btnpos = {790, 385};
    button_t *btn = create_button(bpath, rct2, btnpos, true);

    set_button_events(btn, &on_fight_escape);
    set_tooltip(btn, "Escape fight");
    register_button(panel, btn);
}