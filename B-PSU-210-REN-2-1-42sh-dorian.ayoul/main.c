/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

static shell_t *create_shell(char **env)
{
    shell_t *shell = NULL;

    shell = calloc(1, sizeof(shell_t));
    if (!shell)
        return NULL;
    shell->env = cp_env(env);
    if (!shell->env)
        return NULL;
    shell->variable = create_list();
    if (!shell->variable)
        return NULL;
    if (minimal_env(shell->env) || minimal_var(shell->variable))
        return NULL;
    return shell;
}

int main(int argc, __attribute__((unused))char **argv, char **env)
{
    shell_t *shell = NULL;
    return_t *ret = NULL;
    int error_code = 0;

    if (argc != 1)
        return 84;
    ret = calloc(1, sizeof(return_t));
    if (!ret) {
        dprintf(STDERR_FILENO,"Nice try :)\n");
        return 84;
    }
    shell = create_shell(env);
    if (!shell)
        return 84;
    error_code = main_loop(shell, isatty(STDIN_FILENO), ret);
    destroy_all(shell, ret);
    return error_code;
}