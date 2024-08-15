/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static int check_error(size_t tab_len, return_t *ret, block_t *next)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int fd = 0;

    if (tab_len == 0) {
        ret->error_code = 1;
        return (-1);
    }
    fd = open(next->cmd_block[0], O_WRONLY | O_CREAT | O_APPEND, mode);
    if (fd == -1) {
        ret->error_code = 1;
        error_command("open", strerror(errno));
        return (-1);
    }
    return (fd);
}

void r_double_right(shell_t *shell, return_t *ret,
    block_t *last, block_t *next)
{
    char *str = NULL;
    size_t len = 0;
    size_t tab_len = barray_len(next->cmd_block);
    int fd = check_error(tab_len, ret, next);

    if (fd == -1)
        return;
    if (tab_len != 1)
        get_new_cmd(last, next);
    executer_fd_by_fd(shell, ret, last, last->fd);
    str = bread_fd(last->fd, READ_SIZE);
    len = strlen(str);
    write(fd, str, len);
    next->fd = WAS_EXEC;
    free_right(last, fd, str);
}
