/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** fight attack entity
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

bool fight_attack_entity(game_t *game, int damage)
{
    int new_health = 0;

    if (!game || !game->curr_fight)
        return (false);
    new_health = game->curr_fight->entity_health;
    new_health -= damage;
    if (new_health <= 0) {
        game->curr_fight->entity_health = new_health;
        game->curr_fight->status = FIGHT_WON;
        return (false);
    }
    game->curr_fight->entity_health = new_health;
    return (true);
}