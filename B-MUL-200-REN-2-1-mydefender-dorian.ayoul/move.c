/*
** EPITECH PROJECT, 2021
** movements functions for NPCS
** File description:
** move
*/

#include "my.h"
#include "my_defender.h"

void coord_last_gestion(game_object_t *npc, float seconds, sfVector2f pos)
{
    if (pos.x < 650)
        sfSprite_move(npc->sprite, (sfVector2f){npc->speed, -(npc->speed)});
    else
        sfSprite_move(npc->sprite, (sfVector2f){npc->speed, 0});
}

void coord_next_gestion(game_object_t *npc, float seconds, sfVector2f pos)
{
    if (pos.y < 415 && pos.x < 440)
        sfSprite_move(npc->sprite, (sfVector2f){npc->speed, npc->speed});
    else if (pos.x < 560)
        sfSprite_move(npc->sprite, (sfVector2f){npc->speed, 0});
    else
        coord_last_gestion(npc, seconds, pos);
}

void coord_gestion(game_object_t *npc, float seconds)
{
    float tmp_spd = npc->speed;
    sfVector2f pos = sfSprite_getPosition(npc->sprite);
    if (pos.y < 160 && pos.x < 440)
        sfSprite_move(npc->sprite, (sfVector2f){0, npc->speed});
    else if (pos.y < 330 && pos.x < 440)
        sfSprite_move(npc->sprite, (sfVector2f){-(npc->speed), tmp_spd / 1.2});
    else
        coord_next_gestion(npc, seconds, pos);
}

void move_ennemies(list_t *npcs)
{
    list_t *temp = npcs;
    sfTime time;
    float seconds = 0;
    while (temp != NULL) {
        time = sfClock_getElapsedTime(temp->data->move_clock);
        seconds = time.microseconds / 100000;
        seconds /= 10;
        if (seconds > 0.005) {
            sfClock_restart(temp->data->move_clock);
            coord_gestion(temp->data, seconds);
        }
        temp = temp->next;
    }
}