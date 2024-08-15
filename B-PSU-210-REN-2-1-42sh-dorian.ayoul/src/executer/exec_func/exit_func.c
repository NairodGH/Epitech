/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static int is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

void exit_func(__attribute__((unused))shell_t *shell, return_t *ret,
    block_t *block)
{
    size_t len = barray_len(block->cmd_block);

    if (len >= 2 && !is_num(block->cmd_block[1])) {
        dprintf(STDERR_FILENO, "exit: Expression Syntax.\n");
        ret->error_code = 1;
        return;
    }
    else if (len != 1)
        ret->error_code = batoi(block->cmd_block[1]);
    if (isatty(STDIN_FILENO))
        bprintf("exit\n");
    ret->is_exited = 1;
}
