/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Create fight status text
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void create_skilltxt(panel_t *pn, skill_t *sk, sfVector2f pos, int i)
{
    txt_t *txt;
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");

    if (font == NULL)
        return;
    txt = create_text(font, sk->name, pos);
    set_text_size(txt, 22);
    set_text_color(txt, sfWhite);
    set_text_type(txt, TXT_FIGHT_SKILL);
    set_text_state(txt, i);
    set_text_events(txt, &on_attack_select);
    set_text_color(txt, sfCyan);
    register_text(pn, txt);
}

sfVector2f get_attack_pos(int itr)
{
    sfVector2f pos = {22, 430};

    while (itr >= 3) {
        itr -= 3;
        pos.x += 200;
    }
    pos.y += 30 * itr;
    return (pos);
}

void create_skill_texts(game_t *game, panel_t *panel)
{
    skill_t *skill;
    int itr = 0;
    list_t *skills;

    if (!game || !game->player)
        return;
    skills = game->player->skills;
    if (!skills)
        return;
    list_foreach(skills, node) {
        skill = (skill_t *) node->value;
        create_skilltxt(panel, skill, get_attack_pos(itr), itr);
        ++itr;
    }
}