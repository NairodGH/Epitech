/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_sgt(core_t *core, client_t *client, UNUSED char *command)
{
    char *buff = NULL;

    if (asprintf(&buff, "sgt %ld\n", core->game->freq) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, buff);
}
