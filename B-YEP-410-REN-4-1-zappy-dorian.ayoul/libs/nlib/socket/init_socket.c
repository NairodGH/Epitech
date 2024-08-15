/*
** EPITECH PROJECT, 2022
** init_socket.c
** File description:
** init_socket
*/

#include "nlib.h"

socket_t *nlib_init_socket(socket_t *sock, int port, size_t nbr_connection)
{
    sock->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock->fd < 0) {
        fprintf(stderr, "[ERROR] %s\n", (strerror(errno)));
        return NULL;
    }
    sock->addr->sin_family = AF_INET;
    sock->addr->sin_port = htons(port);
    sock->addr->sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock->fd, (struct sockaddr *)sock->addr,
                        sizeof(sockaddr_in_t)) < 0) {
        fprintf(stderr, "[ERROR] %s\n", (strerror(errno)));
        return NULL;
    }
    if (listen(sock->fd, nbr_connection) < 0) {
        fprintf(stderr, "[ERROR] %s\n", (strerror(errno)));
        return NULL;
    }
    return sock;
}
