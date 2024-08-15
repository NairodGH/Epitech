/*
** EPITECH PROJECT, 2021
** B-PSU-200-REN-2-1-mysokoban-evan.mevel
** File description:
** Created by evan
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

static void add_tolist(list **li, char *line, ssize_t le)
{
    ssize_t length = line[le - 1] == '\n' ? le : le + 1;
    char *s = malloc(sizeof(char) * length);

    for (int i = 0; i < length - 1; i++) {
        s[i] = line[i];
    }
    s[length - 1] = '\0';
    l_add(li, s);
}

static void add_l(list **li, FILE *fp)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t le = getline(&line, &len, fp);

    if (le > 0) {
        add_tolist(li, line, le);
        add_l(li, fp);
    }
}

list **parse_filec(const char *file)
{
    FILE *fp = fopen(file, "r");
    list **li;

    if (fp == NULL) {
        return NULL;
    }
    li = l_create();
    add_l(li, fp);
    return li;
}
