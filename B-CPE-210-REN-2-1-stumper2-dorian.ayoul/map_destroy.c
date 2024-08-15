/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** destroy
*/

#include "map.h"
#include <stdlib.h>

void destroy_bmap(map *m)
{
    for (int i = 0; i < m->le; i++) {
        free(m->m[i]);
    }
    free(m->m);
    free(m);
}
