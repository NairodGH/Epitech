/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Created by evan
*/

#include "list.h"

list **l_create(void)
{
    list **li = malloc(sizeof(list*));

    *li = NULL;
    return li;
}

void l_destroy(list **li)
{
    list *e = *li;
    list *next;

    while (e != NULL) {
        next = e->next;
        free(e);
        e = next;
    }
    free(li);
}

void l_add(list **li, void *v)
{
    list *el = malloc(sizeof(list));
    list *e = *li;

    el->v = v;
    el->next = NULL;
    if (e == NULL) {
        *li = el;
        return;
    }
    while (e->next != NULL) {
        e = e->next;
    }
    e->next = el;
}

void l_remove(list **li, void *v)
{
    list *e = *li;
    list *next;

    if (e->v == v) {
        *li = e->next;
        free(e);
        return;
    }
    while (e->next != NULL && e->next->v != v) {
        e = e->next;
    }
    if (e->next == NULL) {
        return;
    }
    next = e->next;
    e->next = next->next;
    free(next);
}

void l_removel(list **li, list *el)
{
    list *e = *li;

    if (e == el) {
        *li = e->next;
        free(e);
        return;
    }
    while (e->next != el && e->next != NULL) {
        e = e->next;
    }
    if (e->next == NULL) {
        return;
    }
    e->next = el->next;
    free(el);
}