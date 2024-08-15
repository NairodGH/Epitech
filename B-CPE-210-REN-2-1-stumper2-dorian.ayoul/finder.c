/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** finder
*/

#include "map.h"

int correct(int d, int le)
{
    if (d < 0) {
        d *= -1;
    }
    if (d > ((le + 1) / 2)) {
        d -= ((le + 1) / 2);
    }
    return d;
}

int dist(map *m, pos g, pos goal)
{
    int dx = correct(goal.x - g.x, m->linele);
    int dy = correct(goal.y - g.y, m->le);

    return dx + dy;
}

void is_closest(map *m, pos goal, pos *cg, int *dis)
{
    int di = dist(m, m->g, goal);

    if (*dis == -1 || di < *dis) {
        *dis = di;
        *cg = goal;
    }
}

pos find_close(map *m, list **li)
{
    int dist = -1;
    pos cg = {-1, -1};
    list *e = *li;

    while (e != NULL) {
        is_closest(m, *((pos*)e->v), &cg, &dist);
        e = e->next;
    }
    return cg;
}

pos find_closest(map *m)
{
    pos tok = find_close(m, m->tokens);
    pos food = find_close(m, m->food);

    if (tok.x == -1) {
        return food;
    }
    if (food.x == -1) {
        return tok;
    }
    return dist(m, m->g, tok) <= dist(m, m->g, food) ? tok : food;
}
