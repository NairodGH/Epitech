/*
** EPITECH PROJECT, 2022
** eject_player.c
** File description:
** eject_player ai
*/

#include "zappy_ai.h"

int eject_player(UNUSED client_t *client, char *str)
{
    if (strcmp(str, "ok") == 0) {
        printf("%s[COMMAND]%s Eject done\n", B, W);
        return 0;
    }
    return 1;
}
