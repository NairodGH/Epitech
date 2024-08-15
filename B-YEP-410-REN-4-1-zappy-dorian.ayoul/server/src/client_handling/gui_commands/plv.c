/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static trantorian_t *verif_trant(core_t *core, char *command)
{
    char *uuid = strtok(command, " \t#");
    trantorian_t *trantorian = NULL;

    if (uuid == NULL) {
        fprintf(stderr, "[ERROR] GUI unknown parameter\n");
        return NULL;
    }
    trantorian = game_get_trantorian(core, uuid);
    if (trantorian == NULL) {
        fprintf(stderr, "[ERROR] GUI unknown trantorian\n");
        return NULL;
    }
    return trantorian;
}

void command_plv(core_t *core, client_t *client, char *command)
{
    trantorian_t *trantorian = verif_trant(core, command);
    char *temp = NULL;

    if (trantorian == NULL)
        return command_sbp(core, client);
    if (asprintf(&temp, "plv %s %ld\n", trantorian->uuid,
            trantorian->level) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, temp);
}
