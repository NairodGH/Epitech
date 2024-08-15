/*
** EPITECH PROJECT, 2022
** Include
** File description:
** main
*/

#include "server.h"

void set_read_fds(server_t *serv, fd_set *fds)
{
    node_t *node = NULL;
    client_t *client = NULL;

    FD_ZERO(fds);
    FD_SET(serv->socket->fd, fds);
    foreach(serv->clients->head, node) {
        client = (client_t *)node->data;
        FD_SET(client->sock->fd, fds);
    }
}

void set_write_fds(server_t *serv, fd_set *fds)
{
    node_t *node = NULL;
    client_t *client = NULL;

    FD_ZERO(fds);
    foreach(serv->clients->head, node) {
        client = (client_t *)node->data;
        FD_SET(client->sock->fd, fds);
    }
}
