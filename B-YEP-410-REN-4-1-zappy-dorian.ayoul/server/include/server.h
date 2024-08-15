/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef SERVER_H
    #define SERVER_H

    #define MAX_CLI 512

    #include <stdio.h>

    #include "list.h"
    #include "nlib.h"

    #include "client.h"

typedef struct {
    int port;
    socket_t *socket;
    list_t *clients;
    list_t *commands_to_send;
} server_t;

server_t *server_create(int port);
void server_destroy(server_t *server);

void command_add_client(command_t *command, client_t *client);
void command_add_def_clients(command_t *commands, list_t *clients);
void command_add_gui_clients(command_t *commands, list_t *clients);

#endif // SERVER_H
