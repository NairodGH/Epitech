/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** handle health
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void handle_health(ENGPANEL)
{
    sfClock *clock;
    player_t *player;

    if (!game || !game->player)
        return;
    player = game->player;
    clock = player->regen_clock;
    if (!clock)
        return;
    if (sfClock_getElapsedTime(clock).microseconds / 1000 < 1000)
        return;
    if (player->food_level <= 0)
        --player->health;
    else if (player->food_level >= 75 && player->health < 100)
        player->health += 1;
    sfClock_restart(clock);
}