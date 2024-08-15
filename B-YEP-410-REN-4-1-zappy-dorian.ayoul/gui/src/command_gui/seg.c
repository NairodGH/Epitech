/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int seg(client_t *client, char *str)
{
    client->win_team = strdup(str);
    return 0;
}
