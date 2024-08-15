/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void client_push_command(server_t *serv, client_t *client, char *buff)
{
    command_t *command = NULL;

    if (buff == NULL || serv == NULL || client == NULL) {
        fprintf(stderr,
            "[ERROR] Null params received on push default client\n");
        if (buff)
            free(buff);
        return;
    }
    command = nlib_command_create(buff);
    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot create command\n");
        if (buff)
            free(buff);
        return;
    }
    command_add_client(command, client);
    list_push_data(serv->commands_to_send, command);
}

void client_def_broadcast_command(server_t *serv, char *buff)
{
    command_t *command = NULL;

    if (buff == NULL || serv == NULL) {
        fprintf(stderr,
            "[ERROR] Null params received on broadcast default client\n");
        if (buff)
            free(buff);
        return;
    }
    command = nlib_command_create(buff);
    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot create command\n");
        if (buff)
            free(buff);
        return;
    }
    command_add_def_clients(command, serv->clients);
    list_push_data(serv->commands_to_send, command);
}

void client_gui_broadcast_command(server_t *serv, char *buff)
{
    command_t *command = NULL;

    if (buff == NULL || serv == NULL) {
        fprintf(stderr,
            "[ERROR] Null params received on broadcast GUI client\n");
        if (buff)
            free(buff);
        return;
    }
    command = nlib_command_create(buff);
    if (command == NULL) {
        fprintf(stderr, "[ERROR] Cannot create command\n");
        if (buff)
            free(buff);
        return;
    }
    command_add_gui_clients(command, serv->clients);
    list_push_data(serv->commands_to_send, command);
}
