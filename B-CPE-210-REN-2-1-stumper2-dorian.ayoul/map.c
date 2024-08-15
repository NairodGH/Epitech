/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** map 
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "map.h"
#include <string.h>

void put_inmap(map *m, list **li);

list **parse_filec(const char *fp);

int put_all(map *m);

void destroy_bmap(map *m);

int isg_invalid(map *m, pos p)
{
    if (m->m[p.y][p.x] == 'G') {
        if (m->g.x == -1) {
            m->g = p;
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

int testg(map *m, pos p)
{
    for (p.x = 0; p.x < m->linele; p.x++) {
        if (isg_invalid(m, p)) {
            return 1;
        }
    }
    return 0;
}

int check_valid(map *m)
{
    pos p = {0, 0};

    m->linele = strlen(m->m[0]);
    m->g.x = -1;
    for (; p.y < m->le; p.y++) {
        if (strlen(m->m[p.y]) != m->linele) {
            return 0;
        }
        if (testg(m, p)) {
            return 0;
        }
    }
    return m->g.x != -1;
}

void destroy_map(map *m)
{
    list *e = *m->tokens;

    while (e != NULL) {
        free(e->v);
        e = e->next;
    }
    l_destroy(m->tokens);
    e = *m->food;
    while (e != NULL) {
        free(e->v);
        e = e->next;
    }
    l_destroy(m->food);
    destroy_bmap(m);
}

map *parse_map(const char *fp)
{
    map *m;
    list **li = parse_filec(fp);
    list *e;

    if (li == NULL) {
        return NULL;
    }
    m = malloc(sizeof(map));
    put_inmap(m, li);
    if (!check_valid(m)) {
        destroy_bmap(m);
        return NULL;
    }
    if (put_all(m)) {
        destroy_map(m);
        return NULL;
    }
    return m;
}
