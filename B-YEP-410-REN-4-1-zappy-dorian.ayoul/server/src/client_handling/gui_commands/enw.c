/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_enw(core_t *core, trantorian_t *trantorian, trantorian_t *egg)
{
    char *buff = NULL;

    if (asprintf(&buff, "enw %s %s %ld %ld\n",
            egg->uuid,
            trantorian->uuid,
            egg->pos.x,
            egg->pos.y) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
