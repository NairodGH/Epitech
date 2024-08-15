/*
** EPITECH PROJECT, 2021
** animations funcs
** File description:
** animations
*/

#include "my.h"
#include "my_defender.h"

void anim_down(game_object_t *npc, float seconds)
{
    sfIntRect rect;
    if (seconds >= 0.1) {
        sfClock_restart(npc->anim_clock);
        rect = sfSprite_getTextureRect(npc->sprite);
        if (rect.left <= npc->rect.left * 3) {
            rect.left += npc->rect.left;
            sfSprite_setTextureRect(npc->sprite, rect);
        }
        else
            sfSprite_setTextureRect(npc->sprite, npc->rect);
    }
}

void anim_single(game_object_t *npc, float seconds)
{
    switch (npc->direction) {
    case 0:
        anim_down(npc, seconds);
        break;
    }
}

void anim_npcs(list_t *npcs)
{
    list_t *temp = npcs;
    sfTime time;
    float seconds = 0;
    while (temp != NULL) {
        time = sfClock_getElapsedTime(temp->data->anim_clock);
        seconds = time.microseconds / 100000;
        seconds /= 10;
        anim_single(temp->data, seconds);
        temp = temp->next;
    }
}