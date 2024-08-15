/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

void r_and(shell_t *shell, return_t *ret, block_t *last, block_t *next)
{
    if (!shell || !ret || !last)
        return;
    if (last->fd == -1)
        next->fd = -1;
    else {
        if (last->fd > 0)
            executer_by_fd(shell, ret, last, last->fd);
        else
            executer(shell, ret, last);
    }
    if (ret->error_code != 0)
        next->fd = -1;
}