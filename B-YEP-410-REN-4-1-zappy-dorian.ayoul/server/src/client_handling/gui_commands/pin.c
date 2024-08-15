/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *command_pin_get_buff(core_t *core, trantorian_t *trantorian)
{
    char *buff = NULL;

    if (asprintf(&buff, "pin %s %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
            trantorian->uuid,
            core->game->map->width, core->game->map->height,
            trantorian->inventory->food,
            trantorian->inventory->linemate,
            trantorian->inventory->deraumere,
            trantorian->inventory->sibur,
            trantorian->inventory->mendiane,
            trantorian->inventory->phiras,
            trantorian->inventory->thystame) == -1)
        return NULL;
    return buff;
}

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

void command_pin(core_t *core, client_t *client, char *command)
{
    trantorian_t *trantorian = verif_trant(core, command);
    char *buff = NULL;

    if (trantorian == NULL)
        return command_sbp(core, client);
    buff = command_pin_get_buff(core, trantorian);
    if (buff == NULL) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return;
    }
    client_push_command(core->server, client, buff);
}
