/*
** EPITECH PROJECT, 2021
** funcs to make NPCS alive
** File description:
** npcs
*/

#include "my.h"
#include "my_defender.h"

char *get_ennemy_path(int type)
{
    char base[] = "sprites/enemy";
    char ext[] = ".png";
    char mid = int_to_len(type);
    char *result = malloc(sizeof(char) * my_strlen(base) + my_strlen(ext) + 2);
    result = my_strcpy(result, base);
    result[my_strlen(base)] = mid;
    result[my_strlen(base) + 1] = '\0';
    result = my_strcat(result, ext);
    return result;
}

void add_ennemies(list_t **enemies, int number, int type, sfClock *gtime)
{
    sfTime time = sfClock_getElapsedTime(gtime);
    size_t seconds = time.microseconds / 10000;
    list_t *temp;
    char *path = get_ennemy_path(type);
    int off = 0;
    srand(seconds);
    for (int i = 0; i != number; i++) {
        list_stack(enemies,
        create_object(path, rdmpos(365, 330, 0 - off, -25 - off), 2));
        if (i > 0)
            temp = temp->next;
        if (i == 0)
            temp = *enemies;
        while (temp->next != NULL)
            temp = temp->next;
        temp->data->rect = get_enemy_rect(temp->data, type);
        sfSprite_setTextureRect(temp->data->sprite, temp->data->rect);
        temp->data->move_clock = sfClock_create();
        temp->data->anim_clock = sfClock_create();
        temp->data->direction = 0, off += 25;
    }
}