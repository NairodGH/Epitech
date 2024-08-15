/*
** EPITECH PROJECT, 2021
** my
** File description:
** Created by Evan
*/

#include "list.h"

int l_foreach(list **li, int (*test)(void *e))
{
    list *e = *li;

    while (e != NULL) {
        if (test(e->v)) {
            return 1;
        }
        e = e->next;
    }
    return 0;
}

void free_inlist(list **li)
{
    list *e = *li;

    while (e != NULL) {
        free(e->v);
        e = e->next;
    }
}

int l_size(list **li)
{
    list *e = *li;
    int i = 0;

    while (e != NULL) {
        i++;
        e = e->next;
    }
    return i;
}