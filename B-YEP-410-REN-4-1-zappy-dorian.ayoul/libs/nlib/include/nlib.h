/*
** EPITECH PROJECT, 2022
** nlib.h
** File description:
** nlib
*/

#ifndef NLIB_H
    #define NLIB_H

    #ifndef SUCCESS
        #define SUCCESS (0)
    #endif
    #ifndef ERROR
        #define ERROR (1)
    #endif
    #ifndef EXIT
        #define EXIT (2)
    #endif

    #define READ_SIZE (4096)

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
    #include <stdarg.h>

    #include "list.h"

typedef struct sockaddr_in sockaddr_in_t;

typedef struct {
    int fd;
    sockaddr_in_t *addr;
} socket_t;

socket_t *nlib_create_socket(void);
socket_t *nlib_init_socket(socket_t *sock, int port, size_t nbr_connection);
void nlib_destroy_socket(socket_t *sock);

int nlib_select_fds(fd_set *readfds, fd_set *writefds);
int nlib_select_fds_time(fd_set *readfd, fd_set *writefds, double time);

char *nlib_read_socket(const socket_t *sock);
int nlib_write_socket(const socket_t *sock, const char *format, ...);

typedef struct {
    list_t *socks;
    char *to_write;
} command_t;

command_t *nlib_command_create(char *buffer);
void nlib_command_destroy(command_t *command);

void nlib_remove_socket_command_list(list_t *command, socket_t *sock);
void nlib_commands_update(list_t *commands, fd_set *writefds);

bool nlib_send_message(list_t *list, socket_t *socket, char *message);

#endif // NLIB_H
