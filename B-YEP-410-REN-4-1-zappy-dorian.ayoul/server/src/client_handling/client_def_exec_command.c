/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const method_t methods[] = {
    {"Forward", command_forward},
    {"Right", command_right},
    {"Left", command_left},
    {"Look", command_look},
    {"Inventory", command_inventory},
    {"Broadcast", command_broadcast},
    {"Connect_nbr", command_connect_nbr},
    {"Fork", command_fork},
    {"Eject", command_eject},
    {"Take", command_take},
    {"Set", command_set},
    {"Incantation", command_incantation},
};

void client_def_search_command(core_t *core, client_t *client, char *command)
{
    for (size_t i = 0; i < sizeof(methods) / sizeof(method_t); i++) {
        if (strncmp(command, methods[i].name, strlen(methods[i].name)) == 0) {
            methods[i].func(core, client, &command[strlen(methods[i].name)]);
            return;
        }
    }
    fprintf(stderr, "[ERROR] Unknown command\n");
    client_push_command(core->server, client, strdup("ko\n"));
}
