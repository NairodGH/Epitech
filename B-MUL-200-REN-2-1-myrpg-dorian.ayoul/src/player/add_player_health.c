/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Add player health
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

void add_player_health(game_t *game, int health)
{
    player_t *player;

    if (!game || !game->player)
        return;
    player = game->player;
    if (player->health + health > 100) {
        player->health = 100;
        return;
    }
    if (player->health + health < 0) {
        player->health = 0;
        return;
    }
    player->health += health;
}