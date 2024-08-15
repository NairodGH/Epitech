/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_pnw(core_t *core, trantorian_t *trantorian)
{
    char *buff = NULL;

    if (asprintf(&buff, "pnw #%s %ld %ld %d %ld %s\n",
            trantorian->uuid,
            trantorian->pos.x,
            trantorian->pos.y,
            (int)trantorian->direction,
            trantorian->level,
            trantorian->team->name) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
