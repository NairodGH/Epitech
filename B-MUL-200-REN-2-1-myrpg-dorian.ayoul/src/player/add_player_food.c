/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Add player food
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>

void add_player_food(game_t *game, int food_level)
{
    player_t *player;

    if (!game || !game->player)
        return;
    player = game->player;
    if (player->food_level + food_level > 100) {
        player->food_level = 100;
        return;
    }
    if (player->food_level + food_level < 0) {
        player->food_level = 0;
        return;
    }
    player->food_level += food_level;
}