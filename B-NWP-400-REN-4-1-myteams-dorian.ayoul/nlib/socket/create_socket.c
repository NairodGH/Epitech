/*
** EPITECH PROJECT, 2022
** create_socket.c
** File description:
** create_socket
*/

#include "nlib.h"

socket_t *create_socket(void)
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
