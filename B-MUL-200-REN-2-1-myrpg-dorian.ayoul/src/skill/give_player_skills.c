/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** give_player_skills
*/

#include <rpg/rpg.h>
#include <rpg/skill.h>
#include <hnep/nstring.h>

bool give_player_skills(game_t *game, player_t *player)
{
    skill_t *skill;
    bool isadd = false;

    if (!game->skills || !player || !player->skills)
        return false;
    list_clear(player->skills);
    list_foreach(game->skills, node) {
        skill = (skill_t *) node->value;
        if (skill->level <= player->level) {
            list_add(player->skills, skill);
            isadd = true;
        }
    }
    return isadd;
}