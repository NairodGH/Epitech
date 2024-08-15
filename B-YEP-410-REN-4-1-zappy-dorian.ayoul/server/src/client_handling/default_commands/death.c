/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_death(core_t *core, client_t *client, UNUSED char *command)
{
    client->trantorian->state = TRANT_DEAD;
    printf("[INFO] Trantorian %s died\n", client->trantorian->uuid);
    client_push_command(core->server, client, strdup("dead\n"));
}
