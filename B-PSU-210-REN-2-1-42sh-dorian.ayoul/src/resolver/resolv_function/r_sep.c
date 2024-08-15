/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

void r_sep(shell_t *shell, return_t *ret, block_t *last, block_t *next)
{
    if (!shell || !ret || !last)
        return;
    if (!next && last->fd == -1)
        return;
    if (last->fd >= 0) {
        if (last->fd > 0)
            executer_by_fd(shell, ret, last, last->fd);
        else
            executer(shell, ret, last);
    }
    if (ret->error_code == 512)
        ret->error_code = 2;
    if (last->save_err == 512)
        last->save_err = 2;
    if (last->save_err != 0)
        ret->error_code = last->save_err;
}