/*
** EPITECH PROJECT, 2022
** init_socket.c
** File description:
** init_socket
*/

#include "nlib.h"

static void *free_socket(socket_t *sock)
{
    if (sock->addr)
        free(sock->addr);
    if (sock)
        free(sock);
    return NULL;
}

socket_t *init_socket(socket_t *sock, int port, size_t nbr_connection)
{
    sock->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock->fd < 0) {
        printf("%s\n", (strerror(errno)));
        return (free_socket(sock));
    }
    sock->addr->sin_family = AF_INET;
    sock->addr->sin_port = htons(port);
    sock->addr->sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock->fd, (struct sockaddr *)sock->addr,
            sizeof(sockaddr_in_t)) < 0) {
        printf("%s\n", (strerror(errno)));
        return (free_socket(sock));
    }
    if (listen(sock->fd, nbr_connection) < 0) {
        printf("%s\n", (strerror(errno)));
        return (free_socket(sock));
    }
    return sock;
}
