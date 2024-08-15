/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init how to play texts
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE void init_move_keys_hwp(ENGPANEL)
{
    init_txt_key_up(engine, game, panel);
    init_txt_key_left(engine, game, panel);
    init_txt_key_right(engine, game, panel);
    init_txt_key_down(engine, game, panel);
}

void init_texts_hwp(ENGPANEL)
{
    init_move_keys_hwp(engine, game, panel);
    init_txt_key_inv(engine, game, panel);
    init_txt_key_ach(engine, game, panel);
    init_txt_key_interact(engine, game, panel);
    init_txt_key_player(engine, game, panel);
    init_txt_key_quests(engine, game, panel);
}