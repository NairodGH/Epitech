/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_pie(core_t *core, trantorian_t *trantorian, bool result)
{
    char *buff = NULL;

    if (asprintf(&buff, "pie %ld %ld %d\n",
            trantorian->pos.x,
            trantorian->pos.y,
            (int)result) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
