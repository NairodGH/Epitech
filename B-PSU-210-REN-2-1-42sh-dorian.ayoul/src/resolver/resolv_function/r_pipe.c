/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

void r_pipe(shell_t *shell, return_t *ret, block_t *last, block_t *next)
{
    if (last->fd < 0)
        next->fd = -1;
    if (last->fd > 0) {
        executer_fd_by_fd(shell, ret, last, last->fd);
        next->fd = last->fd;
    }
    if (last->fd == 0) {
        executer_fd(shell, ret, last);
        next->fd = last->fd;
    }
    if (ret->error_code != 0 && last->save_err == 0)
        next->save_err = ret->error_code;
    if (last->save_err != 0)
        next->save_err = last->save_err;
}