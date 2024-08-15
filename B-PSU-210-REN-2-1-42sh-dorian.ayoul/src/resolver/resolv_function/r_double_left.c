/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

static int error_handling_double_left(char **cmd_block, return_t *ret)
{
    size_t len = barray_len(cmd_block);

    if (len < 1) {
        ret->error_code = 1;
        return 1;
    }
    return 0;
}

static char *asprintf_values(char *result, char *readed)
{
    char *temp = NULL;

    if (!result && asprintf(&temp, "%s", readed) == -1) {
        free(result);
        free(readed);
        return NULL;
    }
    else if (result && asprintf(&temp, "%s%s", result, readed) == -1) {
        free(result);
        free(readed);
        return NULL;
    }
    free(result);
    return temp;
}

static char *read_loop(block_t *next)
{
    char *result = NULL;
    char *readed = NULL;
    size_t len_readed = 0;

    while (1) {
        printf("? ");
        readed = NULL;
        if (getline(&readed, &len_readed, stdin) == EOF) {
            clearerr(stdin);
            if (readed)
                free(readed);
            return result;
        }
        if (readed && !strncmp(next->cmd_block[0],
            readed, strlen(readed) - 1)) {
            free(readed);
            return result;
        }
        else result = asprintf_values(result, readed);
        free(readed);
    }
}

static int double_left(shell_t *shell, return_t *ret,
    block_t *last, block_t *next)
{
    size_t len = barray_len(next->cmd_block);
    char *result = NULL;
    int pipefd[2] = {0};

    if (len != 1)
        get_new_cmd(last, next);
    result = read_loop(next);
    pipe(pipefd);
    if (result) {
        write(pipefd[1], result, strlen(result));
        free(result);
    }
    close(pipefd[1]);
    if (next->need_fd)
        executer_fd_by_fd(shell, ret, last, pipefd[0]);
    else executer_by_fd(shell, ret, last, pipefd[0]);
    close(pipefd[0]);
    next->fd = last->fd;
    return 0;
}

void r_double_left(shell_t *shell, return_t *ret, block_t *last, block_t *next)
{
    if (error_handling_double_left(next->cmd_block, ret))
        ret->error_code = 1;
    else
        double_left(shell, ret, last, next);
}
