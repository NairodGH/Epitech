/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

void destroy_all(shell_t *shell, return_t *ret)
{
    if (ret)
        free(ret);
    if (!shell)
        return;
    if (shell->env)
        destroy_list(shell->env, destroy_env);
    if (shell->parsing)
        destroy_list(shell->parsing, destroy_elem_block);
    if (shell->variable)
        destroy_list(shell->variable, destroy_variable);
    free(shell);
}
