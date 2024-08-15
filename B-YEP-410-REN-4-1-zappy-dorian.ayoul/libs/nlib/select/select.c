/*
** EPITECH PROJECT, 2022
** select.c
** File description:
** select
*/

#include "nlib.h"

int nlib_select_fds(fd_set *readfds, fd_set *writefds)
{
    int ret_val = 0;

    ret_val = select(FD_SETSIZE, readfds, writefds, NULL, NULL);
    if (ret_val == -1) {
        printf("%s\n", (strerror(errno)));
        return (-1);
    }
    return ret_val;
}

int nlib_select_fds_time(fd_set *readfd, fd_set *writefds, double time)
{
    int ret_val = 0;
    struct timeval tv = {
        .tv_sec = (long)time,
        .tv_usec = (time - tv.tv_sec) * 1000,
    };

    ret_val = select(FD_SETSIZE, readfd, writefds, NULL, &tv);
    if (ret_val == -1) {
        perror(strerror(errno));
    }
    return ret_val;
}
