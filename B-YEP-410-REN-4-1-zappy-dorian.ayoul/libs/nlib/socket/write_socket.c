/*
** EPITECH PROJECT, 2022
** read_socket.c
** File description:
** read_socket
*/

#include "nlib.h"

int nlib_write_socket(const socket_t *sock, const char *format, ...)
{
    va_list args = {0};
    int ret = 0;

    va_start(args, format);
    ret = vdprintf(sock->fd, format, args);
    va_end(args);
    return ret;
}
