/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const method_t methods[] = {
    {"msz", command_msz},
    {"bct", command_bct},
    {"mct", command_mct},
    {"tna", command_tna},
    {"ppo", command_ppo},
    {"plv", command_plv},
    {"pin", command_pin},
    {"sgt", command_sgt},
    {"sst", command_sst},
};

void client_gui_search_command(core_t *core, client_t *client, char *command)
{
    for (size_t i = 0; i < sizeof(methods) / sizeof(method_t); i++) {
        if (strncmp(command, methods[i].name, strlen(methods[i].name)) == 0) {
            methods[i].func(core, client, &command[strlen(methods[i].name)]);
            return;
        }
    }
    fprintf(stderr, "[ERROR] GUI unknown command\n");
    command_suc(core, client);
}
