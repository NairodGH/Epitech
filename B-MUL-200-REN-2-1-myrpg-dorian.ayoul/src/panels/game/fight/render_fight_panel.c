/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** render fight panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void tick_fight(ENGPANEL)
{

}

void render_fight(ENGPANEL)
{
    update_fight_hpplayer(game, panel);
    update_fight_hpentity(game, panel);
    wait_for_attack(panel, game);
    render_heal_button(engine, game, panel);
}