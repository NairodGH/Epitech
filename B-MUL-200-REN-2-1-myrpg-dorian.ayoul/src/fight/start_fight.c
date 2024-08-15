/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** start_fight
*/

#include <rpg/rpg.h>

void start_fight(game_t *game, entity_t *entity)
{
    if (!game->player || !entity || !entity->fight || game->curr_fight)
        return;
    game->curr_fight = ncalloc(1, sizeof(fight_t));
    if (game->curr_fight == NULL)
        return;
    game->curr_fight->status = FIGHT_ONGOING;
    game->curr_fight->nextattack = sfClock_create();
    game->curr_fight->entity = entity;
    game->curr_fight->entity_health = entity->fight->health;
}