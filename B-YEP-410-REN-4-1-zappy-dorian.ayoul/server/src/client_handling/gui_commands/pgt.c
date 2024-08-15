/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_pgt(core_t *core, trantorian_t *trantorian, size_t nb_get)
{
    char *buff = NULL;

    if (asprintf(&buff, "pgt %s %ld\n", trantorian->uuid, nb_get) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
