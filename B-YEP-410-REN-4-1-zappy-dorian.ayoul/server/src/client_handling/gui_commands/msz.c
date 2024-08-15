/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_msz(core_t *core, client_t *client, UNUSED char *command)
{
    char *buffer = NULL;

    if (asprintf(&buffer, "msz %ld %ld\n", core->game->map->width,
            core->game->map->height) == -1) {
        fprintf(stderr, "[ERROR] Unable to allocate memory\n");
        return;
    }
    client_push_command(core->server, client, buffer);
}
