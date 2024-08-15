/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

void env_func(shell_t *shell, return_t *ret, block_t *block)
{
    if (barray_len(block->cmd_block) != 1) {
        ret->error_code = 127;
        dprintf(STDERR_FILENO, "env: ‘%s’: No such file or directory\n",
        block->cmd_block[1]);
    }
    else {
        print_env(shell->env);
        ret->error_code = 0;
    }
}
