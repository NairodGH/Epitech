/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/

#include "server.h"

int list(lcli_t *list, char **arg)
{
    if (arg)
        dprintf(list->client->fd, "\n");
    return 0;
}
