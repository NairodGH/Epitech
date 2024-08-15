/*
** EPITECH PROJECT, 2022
** read_socket.c
** File description:
** read_socket
*/

#include "nlib.h"

static bool nlib_check_end(char *buffer, size_t size_read)
{
    size_t len = strlen("\n\0");

    if (strncmp("\n\0", &buffer[size_read - len], len) == 0)
        return true;
    return false;
}

char *nlib_read_socket(const socket_t *sock)
{
    char *buffer = NULL;
    ssize_t size_read = 0;
    size_t size_total = 0;

    do {
        buffer = realloc(buffer, size_total + READ_SIZE + 1);
        if (buffer == NULL)
            return NULL;
        bzero((void *)((size_t)buffer + (size_t)size_total), READ_SIZE + 1);
        size_read = read(sock->fd, buffer + size_total, READ_SIZE);
        if ((size_read == 0 && size_total == 0) || size_read < 0) {
            free(buffer);
            return NULL;
        }
        size_total += size_read;
    } while (size_read == READ_SIZE &&
        nlib_check_end(&buffer[size_total - size_read], size_read) == false);
    return buffer;
}

// char *nlib_read_socket(const socket_t *sock)
// {
//     char *buffer = calloc(READ_SIZE * 10, sizeof(char));
//     ssize_t size_read = 0;

//     if (buffer == NULL)
//         return NULL;
//     size_read = read(sock->fd, buffer, READ_SIZE);
//     if (size_read <= 0) {
//         free(buffer);
//         return NULL;
//     }
//     return buffer;
// }
