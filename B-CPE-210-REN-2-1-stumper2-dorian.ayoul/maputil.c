/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** maputil
*/

#include <stdlib.h>
#include "map.h"
#include "my.h"

void putline_all(map *m, pos p)
{
    pos *pp;

    if (map_at(m, p) == 'T') {
        pp = malloc(sizeof(pos));
        *pp = p;
        l_add(m->tokens, pp);
        m->tokentot++;
    } else if (map_at(m, p) == 'F') {
        pp = malloc(sizeof(pos));
        *pp = p;
        l_add(m->food, pp);
    }
}

int put_all(map *m)
{
    pos p = {0, 0};

    m->tokens = l_create();
    m->food = l_create();
    m->tokentot = 0;
    for (; p.y < m->le; p.y++) {
        for (p.x = 0; p.x < m->linele; p.x++) {
            putline_all(m, p);
        }
    }
    if (l_size(m->tokens) < 1) {
        return 1;
    }
    return 0;
}

void put_inmap(map *m, list **li)
{
    list *e = *li;

    m->le = l_size(li);
    m->m = malloc(sizeof(char*) * m->le);
    for (int i = 0; i < m->le; i++) {
        m->m[i] = e->v;
        e = e->next;
    }
    l_destroy(li);
}

char map_at(map *m, pos p)
{
    return m->m[p.y][p.x];
}

void print_map(map *m)
{
    my_putstr("Tokens: ");
    my_putnbr(m->tokenfind);
    my_putchar('/');
    my_putnbr(m->tokentot);
    my_putstr("\nMovement points: ");
    my_putnbr(m->moves);
    my_putchar('\n');
    for (int i = 0; i < m->le; i++) {
        my_putstr(m->m[i]);
        my_putchar('\n');
    }
    my_putchar('\n');
}
