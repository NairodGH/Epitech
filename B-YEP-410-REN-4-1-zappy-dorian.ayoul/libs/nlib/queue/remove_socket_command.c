/*
** EPITECH PROJECT, 2022
** select.c
** File description:
** select
*/

#include "nlib.h"

static void nlib_remove_socket_command(command_t *command, socket_t *sock)
{
    node_t *node = NULL;
    node_t *safe = NULL;

    foreach_safe(command->socks->head, node, safe) {
        if (node->data == sock) {
            list_remove_node(command->socks, node);
            list_destroy_node(node, NULL);
        }
    }
}

void nlib_remove_socket_command_list(list_t *command, socket_t *sock)
{
    node_t *node = NULL;
    command_t *temp = NULL;

    foreach(command->head, node) {
        temp = (command_t *)node->data;
        nlib_remove_socket_command(temp, sock);
    }
}
