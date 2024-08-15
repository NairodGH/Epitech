/*
** EPITECH PROJECT, 2022
** info.c
** File description:
** info
*/

#include "server.h"

int info(lcli_t *list, char **arg)
{
    if (arg)
        dprintf(list->client->fd, "\n");
    return 0;
}
