/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_connect_nbr(core_t *core, client_t *client, UNUSED char *command)
{
    char *rep = NULL;

    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    if (asprintf(&rep, "%ld\n", client->trantorian->team->cli_max -
            client->trantorian->team->cli_sub) == -1) {
        fprintf(stderr, "[ERROR] Failed to malloc\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client_push_command(core->server, client, rep);
}
