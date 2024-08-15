/*
** EPITECH PROJECT, 2022
** fork_player.c
** File description:
** fork_player ai
*/

#include "zappy_ai.h"

int fork_player(client_t *client, UNUSED char *str)
{
    client->player->fork = false;
    printf("%s[COMMAND]%s Fork done\n", B, W);
    return 0;
}
