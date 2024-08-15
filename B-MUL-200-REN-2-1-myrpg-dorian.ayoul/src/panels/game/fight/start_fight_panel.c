/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init fight panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void init_fight_buttons(ENGPANEL)
{
    create_fight_escape_button(panel);
    create_fight_heal_button(panel);
}

PRIVATE void init_fight_objects(ENGPANEL)
{
    init_fight_background(panel);
    init_enemy_fight(panel, game);
    init_player_fight(panel, game);
    init_fight_hpentity(panel);
    init_fight_hpplayer(panel);
}

PRIVATE void init_fight_texts(ENGPANEL)
{
    create_fight_status_txt(panel);
    create_skill_texts(game, panel);
}

void start_fight_panel(ENGPANEL)
{
    init_fight_objects(engine, game, panel);
    init_fight_buttons(engine, game, panel);
    init_fight_texts(engine, game, panel);
    play_seffect(game, engine, "assets/sounds/fight-start.ogg");
}