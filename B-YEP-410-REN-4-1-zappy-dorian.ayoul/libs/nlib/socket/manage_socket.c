/*
** EPITECH PROJECT, 2022
** create_socket.c
** File description:
** create_socket
*/

#include "nlib.h"

socket_t *nlib_create_socket(void)
{
    socket_t *sock = calloc(1, sizeof(socket_t));

    if (sock == NULL)
        return NULL;
    sock->addr = calloc(1, sizeof(sockaddr_in_t));
    if (sock->addr == NULL) {
        free(sock);
        return NULL;
    }
    return sock;
}

void nlib_destroy_socket(socket_t *sock)
{
    if (sock == NULL)
        return;
    if (sock->addr != NULL) {
        free(sock->addr);
    }
    if (sock->fd != -1) {
        close(sock->fd);
    }
    free(sock);
}
