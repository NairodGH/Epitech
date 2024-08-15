/*
** EPITECH PROJECT, 2021
** htiboxes funcs
** File description:
** hitboxes
*/

#include "my.h"
#include "my_defender.h"

int check_hit(game_object_t *npc, tower t)
{
    sfFloatRect border = sfSprite_getGlobalBounds(t.sprite);
    border.height += 20;
    border.width += 20;
    sfVector2f pos = sfSprite_getPosition(npc->sprite);
    sfTime time = sfClock_getElapsedTime(t.cd);
    int seconds = time.microseconds / 1000000;
    if (seconds > 1 &&
    sfFloatRect_contains(&border, pos.x, pos.y) && t.stage != 0) {
        sfClock_restart(t.cd);
        npc->life -= 1;
    }
}

int is_hit(list_t *npcs, tower *towers)
{
    int res = 0;
    list_t *temp = npcs;
    while (temp != NULL) {
        for (int i = 0; i != 8; i++) {
            res = check_hit(temp->data, towers[i]);
        }
        temp = temp->next;
    }
    return res;
}