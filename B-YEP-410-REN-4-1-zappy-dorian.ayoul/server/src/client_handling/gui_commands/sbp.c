/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void command_sbp(core_t *core, client_t *client)
{
    client_push_command(core->server, client, strdup("sbp\n"));
}
