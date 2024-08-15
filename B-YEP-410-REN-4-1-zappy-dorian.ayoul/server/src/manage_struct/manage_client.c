/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "client.h"
#include "core.h"

void client_destroy_command(char *command)
{
    if (command != NULL)
        free(command);
}

command_handler_t *handler_create(void)
{
    return calloc(1, sizeof(command_handler_t));
}

void handler_clear(command_handler_t *handler)
{
    if (handler == NULL)
        return;
    if (handler->params != NULL)
        free(handler->params);
    handler->command = NULL;
    handler->params = NULL;
    handler->command_it = 0;
}

client_t *client_create(int fd)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->sock = nlib_create_socket();
    client->command_list = list_create();
    client->handler = handler_create();
    if (client->sock == NULL || client->command_list == NULL ||
            client->handler == NULL)
        return NULL;
    client->sock->fd = fd;
    return client;
}

void client_destroy(client_t *client)
{
    if (client == NULL)
        return;
    if (client->sock != NULL)
        nlib_destroy_socket(client->sock);
    if (client->handler)
        free(client->handler);
    if (client->command_list != NULL)
        list_destroy(client->command_list,
            (void (*)(void *))client_destroy_command);
    free(client);
}
