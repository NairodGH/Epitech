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

PRIVATE void hide_skills(ENGPANEL)
{
    txt_t *txt;

    if (!panel || !game)
        return;
    if (!panel->texts)
        return;
    list_foreach(panel->texts, node) {
        txt = (txt_t *) node->value;
        if (!txt || get_text_type(txt) != TXT_FIGHT_SKILL)
            continue;
        set_text_visibility(txt, false);
    }
}

void on_attack_select(ENGPANEL, txt_t *txt)
{
    skill_t *skill = get_attack_by_id(game, txt->state);

    if (!skill)
        return;
    play_seffect(game, engine, "assets/sounds/hurt.ogg");
    hide_skills(engine, game, panel);
    if (!fight_attack_entity(game, skill->attack)) {
        won_fight(engine, game);
        return;
    }
    fight_attack_player(game);
    update_fight_stext(panel, "Waiting for enemy's turn...\n");

}