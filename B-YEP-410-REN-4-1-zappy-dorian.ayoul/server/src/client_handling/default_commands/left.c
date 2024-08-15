/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void left_e(core_t *core, client_t *client, UNUSED char *command)
{
    client->trantorian->direction--;
    if (client->trantorian->direction < 0 || client->trantorian->direction > 3)
        client->trantorian->direction = 3;
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_left(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = left_e;
    client->handler->command_it = 7;
}
