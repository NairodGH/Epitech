/*
** EPITECH PROJECT, 2022
** nlib.h
** File description:
** nlib
*/

#ifndef NLIB_H
    #define NLIB_H

    #include <sys/socket.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <linux/limits.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>

typedef struct sockaddr_in sockaddr_in_t;

typedef struct {
    int fd;
    sockaddr_in_t *addr;
} socket_t;

socket_t *create_socket(void);
socket_t *init_socket(socket_t *sock, int port, size_t nbr_connection);
void destroy_socket(socket_t *sock);

int select_fds(fd_set *readfds, fd_set *writefds);
int select_fds_time(fd_set *readfd, fd_set *writefds, double time);

/**
* @brief Read a socket and return the buffer.
*
* @param fd The socket to read.
* @param buffer_size Send your size_t address to get the size of the buffer.
* @return The socket content.
*/
char *read_socket(int fd);

#endif // NLIB_H
