/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight attack player
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <hnep/nstring.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void display_skill_attacks(panel_t *panel)
{
    txt_t *txt;

    if (!panel || !panel->texts)
        return;
    list_foreach(panel->texts, node) {
        txt = (txt_t *) node->value;
        if (get_text_type(txt) != TXT_FIGHT_SKILL)
            continue;
        set_text_visibility(txt, true);
    }
}

PRIVATE void display_entity_sattack(game_t *gm, panel_t *pn, skill_t *sk)
{
    char *txt;

    if (!pn || !sk)
        return;
    play_seffect(gm, gm->engine, "assets/sounds/knife.ogg");
    if (gm->player && gm->player->health <= 0) {
        play_seffect(gm, gm->engine, "assets/sounds/knife.ogg");
        lost_fight(gm->engine, gm);
        return;
    }
    txt = string_format("Enemy used attack: %s", sk->name);
    update_fight_stext(pn, txt);
    display_skill_attacks(pn);
}

void wait_for_attack(panel_t *panel, game_t *game)
{
    sfClock *clock;
    skill_t *skill;

    if (!game || !game->curr_fight)
        return;
    clock = game->curr_fight->nextattack;
    if (!clock || !game->player)
        return;
    if (game->curr_fight->status != FIGHT_WAIT_FOR_ENEMY)
        return;
    if (sfClock_getElapsedTime(clock).microseconds / 1000 < 1200)
        return;
    game->curr_fight->status = FIGHT_ONGOING;
    skill = fight_turn_ia(game->curr_fight, game->player);
    display_entity_sattack(game, panel, skill);
    sfClock_restart(clock);
}

bool fight_attack_player(game_t *game)
{
    if (!game || !game->curr_fight)
        return (false);
    game->curr_fight->status = FIGHT_WAIT_FOR_ENEMY;
    sfClock_restart(game->curr_fight->nextattack);
    return (true);
}