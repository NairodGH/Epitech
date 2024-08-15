/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_smg(core_t *core, char *message)
{
    char *buff = NULL;

    if (asprintf(&buff, "smg %s\n", message) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
