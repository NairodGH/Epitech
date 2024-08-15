/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** child_command
*/

#include "42sh.h"

void get_binary_path(list_t *env, char **env_tab,
    return_t *ret, block_t *block)
{
    char *line = get_env_value("PATH", env);
    char **tab = NULL;
    char *file = NULL;

    ret->error_code = 1;
    tab = bstr_array(line, ':');
    if (!tab)
        return;
    if (access(block->cmd_block[0], F_OK) == 0)
        ret->error_code = execve(block->cmd_block[0],
            block->cmd_block, env_tab);
    for (int delay = 0; tab[delay] != NULL; delay++) {
        file = bstrcat_plus(*(tab + delay), "/", block->cmd_block[0]);
        if (access(file, F_OK) == 0)
            ret->error_code = execve(file, block->cmd_block, env_tab);
    }
}

void child_exec(shell_t *shell, return_t *ret, block_t *block)
{
    char **env = env_to_array(shell->env);

    if (strncmp(block->cmd_block[0], "./", 2))
        get_binary_path(shell->env, env, ret, block);
    else
        ret->error_code = execve(block->cmd_block[0], block->cmd_block, env);
    if (ret->error_code) {
        error_command(block->cmd_block[0], "Command not found");
        kill(getpid(), SIGHUP);
    }
    bfree_array(env);
}

void create_child(shell_t *shell, return_t *ret, block_t *block)
{
    int pid = fork();

    if (pid == 0)
        child_exec(shell, ret, block);
    else
        waitpid(pid, &ret->error_code, 0);
    print_child_error(ret->error_code);
}
