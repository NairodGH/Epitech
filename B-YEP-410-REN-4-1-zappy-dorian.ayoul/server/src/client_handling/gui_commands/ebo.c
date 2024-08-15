/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_ebo(core_t *core, trantorian_t *egg)
{
    char *buff = NULL;

    if (asprintf(&buff, "ebo %s\n", egg->uuid) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
