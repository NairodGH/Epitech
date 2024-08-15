/*
** EPITECH PROJECT, 2022
** destroy_socket.c
** File description:
** destroy_socket
*/

#include "nlib.h"

void destroy_socket(socket_t *sock)
{
    if (sock == NULL)
        return;
    if (sock->addr != NULL) {
        free(sock->addr);
    }
    if (sock->fd != -1) {
        close(sock->fd);
        shutdown(sock->fd, SHUT_RDWR);
    }
    free(sock);
}
