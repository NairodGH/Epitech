/*
** EPITECH PROJECT, 2022
** select.c
** File description:
** select
*/

#include "nlib.h"

command_t *nlib_command_create(char *buffer)
{
    command_t *command = calloc(1, sizeof(command_t));

    if (command == NULL)
        return NULL;
    command->socks = list_create();
    if (command->socks == NULL) {
        free(command);
        return NULL;
    }
    command->to_write = buffer;
    return command;
}

void nlib_command_destroy(command_t *command)
{
    if (command == NULL)
        return;
    if (command->socks != NULL)
        list_destroy(command->socks, NULL);
    if (command->to_write != NULL)
        free(command->to_write);
    free(command);
}

static int write_command(socket_t *sock, command_t *command,
    fd_set *writefds)
{
    if (FD_ISSET(sock->fd, writefds) == 0 ||
        nlib_write_socket(sock, "%s", command->to_write) <= 0) {
        return ERROR;
    }
    return SUCCESS;
}

static int write_command_all(command_t *command, fd_set *writefds)
{
    node_t *node = NULL;
    node_t *temp = NULL;

    foreach_safe(command->socks->head, node, temp) {
        if (write_command(node->data, command, writefds) == ERROR)
            continue;
        list_remove_node(command->socks, node);
        list_destroy_node(node, NULL);
    }
    if (command->socks->lenght == 0)
        return SUCCESS;
    return ERROR;
}

void nlib_commands_update(list_t *commands, fd_set *writefds)
{
    node_t *node = NULL;
    node_t *temp = NULL;
    command_t *command = NULL;

    if (commands == NULL || writefds == NULL)
        return;
    foreach_safe(commands->head, node, temp) {
        command = (command_t *)node->data;
        if (write_command_all(command, writefds) == ERROR)
            continue;
        list_remove_node(commands, node);
        list_destroy_node(node, (void (*)(void *))nlib_command_destroy);
    }
}
