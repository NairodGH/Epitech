/*
** EPITECH PROJECT, 2022
** connect_nbr.c
** File description:
** connect_nbr ai
*/

#include "zappy_ai.h"

int connect_nbr(client_t *client, char *str)
{
    client->unused_slot = atoi(str);
    printf("%s[COMMAND]%s connect_nbr = %d\n", C, W, client->unused_slot);
    return 0;
}
