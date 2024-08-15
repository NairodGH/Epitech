/*
** EPITECH PROJECT, 2022
** read_socket.c
** File description:
** read_socket
*/

#include "nlib.h"

char *read_socket(int fd)
{
    char buffer[4096];
    ssize_t size_read = 0;

    size_read = read(fd, buffer, 4096);
    if (size_read <= 0)
        return NULL;
    buffer[size_read] = '\0';
    return strdup(buffer);
}
