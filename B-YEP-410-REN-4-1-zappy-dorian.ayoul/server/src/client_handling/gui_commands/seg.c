/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_seg(core_t *core, team_t *team_winner)
{
    char *buff = NULL;

    if (asprintf(&buff, "seg %s\n", team_winner->name) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    client_gui_broadcast_command(core->server, buff);
}
