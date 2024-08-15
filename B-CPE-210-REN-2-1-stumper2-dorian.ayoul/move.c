/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** move
*/

#include "map.h"

int newv(int x, int *vx, int le)
{
    if (*vx > 0) {
        x += 1;
        if (x >= le) {
            x = x - le;
        }
        *vx = *vx - 1;
    } else {
        x -= 1;
        if (x < 0) {
            x = x + le - 1;
        }
        *vx = *vx + 1;
    }
    return x;
}

void movex(map *m)
{
    int nx = m->vec.x;
    int gx = newv(m->g.x, &nx, m->linele);

    m->vec.x = nx;
    m->g.x = gx;
}

void movey(map *m)
{
    int ny = m->vec.y;
    int gy = newv(m->g.y, &ny, m->le);

    m->vec.y = ny;
    m->g.y = gy;
}

void move(map *m)
{
    if (m->vec.x != 0) {
        movex(m);
    } else {
        movey(m);
    }
}
