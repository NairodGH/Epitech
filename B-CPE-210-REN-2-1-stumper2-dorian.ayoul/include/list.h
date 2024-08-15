/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Created by evan
*/

#include <stdlib.h>

#ifndef LISTH
#define LISTH

typedef struct list_s list;

struct list_s
{
    void *v;
    list *next;
};

#endif

list **l_create(void);

void l_destroy(list **li);

void l_add(list **li, void *v);

void l_remove(list **li, void *v);

void l_removel(list **li, list *el);

int l_foreach(list **li, int (*test)(void *e));

int l_size(list **li);

void free_inlist(list **li);
