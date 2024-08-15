/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get map relative max
*/

#include <rpg/rpg.h>

double get_rymax(map_t *m)
{
    if (m == NULL)
        return (0);
    return (m->sroll.y + 33 > m->size.y ? m->size.y : m->sroll.y + 33);
}

double get_rxmax(map_t *m)
{
    if (m == NULL)
        return (0);
    return (m->sroll.x + 60 > m->size.x ? m->size.x : m->sroll.x + 60);
}