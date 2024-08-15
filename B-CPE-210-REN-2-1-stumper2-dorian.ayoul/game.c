/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** game basics
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "map.h"

pos find_closest(map *m);

void move(map *m);

void print_map(map *m);

int corr(int i, int di)
{
    if (i > di) {
        return -i + di;
    } else if (i < -di) {
        return -i - di;
    }
    return i;
}

pos movevec(map *m)
{
    pos vec = {m->goal.x - m->g.x, m->goal.y - m->g.y};

    vec.x = corr(vec.x, ((m->linele + 1) / 2));
    vec.y = corr(vec.y, ((m->le + 1) / 2));
    return vec;
}

void rm_inlist(map *m, pos p, list **li)
{
    list *e = *li;
    pos *pp;

    while (e != NULL) {
        pp = e->v;
        if (pp->x == p.x && pp->y == p.y) {
            l_removel(li, e);
            break;
        }
        e = e->next;
    }
}

void play(map *m)
{
    m->m[m->g.y][m->g.x] = '.';
    move(m);
    m->moves--;
    if (m->g.x == m->goal.x && m->g.y == m->goal.y) {
        if (map_at(m, m->goal) == 'T') {
            m->tokenfind++;
            rm_inlist(m, m->goal, m->tokens);
        } else if (map_at(m, m->goal) == 'F') {
            m->moves = m->movetot;
            rm_inlist(m, m->goal, m->food);
        }
        m->goal = find_closest(m);
        m->vec = movevec(m);
    }
    m->m[m->g.y][m->g.x] = 'G';
    print_map(m);
}

void ginger(map *m)
{
    m->tokenfind = 0;
    m->goal = find_closest(m);
    m->vec = movevec(m);
    print_map(m);
    while (m->moves > 0 && m->tokenfind != m->tokentot) {
        play(m);
    }
    if (m->tokenfind >= m->tokentot) {
        write(0, "Ginger never loses!\n", 20);
    } else {
        write(0, "Ginger is too old for this!\n", 28);
    }
    destroy_map(m);
}
