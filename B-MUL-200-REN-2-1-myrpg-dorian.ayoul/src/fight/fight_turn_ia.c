/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** remove_itemstack
*/

#include <rpg/rpg.h>
#include <time.h>

skill_t *fight_turn_ia(fight_t *fight, player_t *player)
{
    skill_t *skill;
    int r;

    if (fight == NULL || player == NULL)
        return NULL;
    srand(time(NULL));
    r = (rand() % fight->entity->fight->skills->length);
    skill = (skill_t *) list_get_value(fight->entity->fight->skills, r);
    if (skill == NULL)
        return NULL;
    player->health -= skill->attack;
    if (player->health < 0)
        player->health = 0;
    return skill;
}