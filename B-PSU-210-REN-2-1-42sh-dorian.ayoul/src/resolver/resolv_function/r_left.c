/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static int free_left(block_t *last, int fd, block_t *next, int stdin_save)
{
    next->fd = WAS_EXEC;
    close(fd);
    if (last->fd > 0)
        close(last->fd);
    if (dup2(stdin_save, STDIN_FILENO) == -1) {
        error_command("dup2", strerror(errno));
        return (1);
    }
    close(stdin_save);
    return (0);
}

static int check_error(size_t tab_len, return_t *ret, block_t *next)
{
    int fd = 0;

    if (tab_len == 0) {
        ret->error_code = 1;
        return (-1);
    }
    fd = open(next->cmd_block[0], O_RDONLY);
    if (fd == -1) {
        ret->error_code = 1;
        error_command("open", strerror(errno));
        return (-1);
    }
    return (fd);
}

static int checker_error(int stdin_save, return_t *ret, int fd)
{
    if (fd == -1)
        return (1);
    if (stdin_save == -1) {
        ret->error_code = 1;
        error_command("dup", strerror(errno));
        return (1);
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        ret->error_code = 1;
        error_command("dup2", strerror(errno));
        return (1);
    }
    return (0);
}

void r_left(shell_t *shell, return_t *ret, block_t *last, block_t *next)
{
    size_t tab_len = barray_len(next->cmd_block);
    int fd = check_error(tab_len, ret, next);
    int stdin_save = dup(STDIN_FILENO);

    if (checker_error(stdin_save, ret, fd) != 0)
        return;
    if (tab_len != 1)
        get_new_cmd(last, next);
    executer(shell, ret, last);
    if (free_left(last, fd, next, stdin_save) != 0)
        ret->error_code = 1;
}
