/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

void handle_food_decrease(player_t *player)
{
    int cnt;

    if (player == NULL)
        return;
    cnt = ++player->tmp_movement_count;
    if (player->food_level <= 0) {
        player->food_level = 0;
        return;
    }
    if (cnt > 375) {
        player->food_level -= 5;
        player->tmp_movement_count = 0;
    }
}