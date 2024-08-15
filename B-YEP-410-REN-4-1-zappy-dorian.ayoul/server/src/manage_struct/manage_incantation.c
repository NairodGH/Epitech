/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "game.h"

incantation_t *incantation_create(size_t level, pos_t pos)
{
    incantation_t *incantation = calloc(1, sizeof(incantation_t));

    if (incantation == NULL)
        return (NULL);
    incantation->trantorians = list_create();
    if (incantation->trantorians == NULL) {
        free(incantation);
        return (NULL);
    }
    incantation->level = level;
    incantation->pos.x = pos.x;
    incantation->pos.y = pos.y;
    return (incantation);
}

void incantation_destroy(incantation_t *incantation)
{
    if (incantation == NULL)
        return;
    list_destroy(incantation->trantorians, NULL);
    free(incantation);
}
