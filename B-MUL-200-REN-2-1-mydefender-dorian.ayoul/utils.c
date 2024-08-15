/*
** EPITECH PROJECT, 2021
** utils funcs
** File description:
** utils
*/

#include "my.h"
#include "my_defender.h"

sfVector2f rdmpos(int xupl, int xdownl, int yupl, int ydownl)
{
    int x = (rand() % (xupl - xdownl + 1) + xdownl);
    int y = (rand() % (yupl - ydownl + 1) + ydownl);
    sfVector2f pos = {x, y};
    return pos;
}

char int_to_len(int n)
{
    return (n + '0');
}

sfIntRect get_enemy_rect(game_object_t *npc, int type)
{
    switch (type) {
    case 1:
        return (sfIntRect){44, 150, 44, 30};
        break;
    }
}

int is_dead(list_t **npcs, game *g)
{
    sfVector2f pos;
    list_t *temp = *npcs;
    for (int i = 0; temp != NULL; i++) {
        pos = sfSprite_getPosition(temp->data->sprite);
        if (pos.x > 800) {
            list_remove(npcs, i);
            g->hp -= 1;
        }
        else if (temp->data->life <= 0)
            list_remove(npcs, i);
        temp = *npcs;
        for (int d = 0; d != i; d++)
            temp = temp->next;
    }
}

game_object_t *create_object(char *path, sfVector2f pos, float speed)
{
    game_object_t *obj = malloc(sizeof(game_object_t));
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->pos = pos;
    obj->life = 3;
    sfSprite_setPosition(obj->sprite, pos);
    obj->speed = speed;
    return (obj);
}