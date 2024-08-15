/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void fork_e(core_t *core, client_t *client, UNUSED char *command)
{
    trantorian_t *trantorian = NULL;

    client->trantorian->team->cli_max++;
    client->trantorian->team->cli_sub++;
    trantorian = trantorian_create(client->trantorian->team,
        client->trantorian->pos.x, client->trantorian->pos.y, false);
    if (trantorian == NULL) {
        fprintf(stderr, "[ERROR] Unable to create trantorian\n");
        return client_push_command(core->server, client, strdup("ko\n"));
    }
    trantorian->state = TRANT_HATCHING;
    trantorian->hatching_time = TRANT_HATCHING_IT;
    list_push_data(core->game->trantorians, trantorian);
    client_push_command(core->server, client, strdup("ok\n"));
    command_pfk(core, client->trantorian);
}

void command_fork(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = fork_e;
    client->handler->command_it = 42;
}
