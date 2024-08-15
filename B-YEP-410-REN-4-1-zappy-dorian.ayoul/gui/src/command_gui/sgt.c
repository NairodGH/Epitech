/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int sgt(client_t *client, char *str)
{
    client->time_unit = atol(str);
    return 0;
}
