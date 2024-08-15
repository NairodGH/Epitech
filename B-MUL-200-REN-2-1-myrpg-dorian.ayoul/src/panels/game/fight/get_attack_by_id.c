/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get attack by id
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

skill_t *get_attack_by_id(game_t *game, int id)
{
    skill_t *skill;
    int itr = 0;
    list_t *skills;

    if (!game || !game->player)
        return (NULL);
    skills = game->player->skills;
    if (!skills)
        return (NULL);
    list_foreach(skills, node) {
        skill = (skill_t *) node->value;
        if (itr == id)
            return (skill);
        ++itr;
    }
    return (NULL);
}