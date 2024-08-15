/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** executer
*/

#include "42sh.h"

static const built_in_t built_in[] = {
    {"cd", cd_func},
    {"exit", exit_func},
    {"setenv", setenv_func},
    {"unsetenv", unsetenv_func},
    {"env", env_func},
    {"echo", echo_func},
    {"set", set_func},
    {"unset", unset_func},

    {NULL, NULL}
};

static int find_built_in(char *command)
{
    for (int i = 0; built_in[i].name; i++)
        if (!bstrcmp(command, built_in[i].name))
            return i;
    return -1;
}

void executer(shell_t *shell, return_t *ret, block_t *block)
{
    int com = find_built_in(block->cmd_block[0]);

    block->fd = WAS_EXEC;
    if (com != -1)
        built_in[com].func(shell, ret, block);
    else
        create_child(shell, ret, block);
}

void executer_fd(shell_t *shell, return_t *ret, block_t *block)
{
    int com = find_built_in(block->cmd_block[0]);
    int stdout_save = dup(STDOUT_FILENO);
    int pipefd[2] = {0};
    int pid;

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    block->fd = pipefd[0];
    if (com != -1)
        built_in[com].func(shell, ret, block);
    else if ((pid = fork()) == 0)
        child_exec(shell, ret, block);
    dup2(stdout_save, STDOUT_FILENO);
    close(stdout_save);
    close(pipefd[1]);
    waitpid(pid, &ret->error_code, WNOHANG);
    print_child_error(ret->error_code);
}

void executer_fd_by_fd(shell_t *shell, return_t *ret, block_t *block, int fd)
{
    int com = find_built_in(block->cmd_block[0]);
    int stdin_save = dup(STDIN_FILENO);
    int stdout_save = dup(STDOUT_FILENO);
    int pipefd[2] = {0};
    int pid;

    pipe(pipefd);
    dup2(pipefd[1], STDOUT_FILENO);
    dup2(fd, STDIN_FILENO);
    block->fd = pipefd[0];
    if (com != -1)
        built_in[com].func(shell, ret, block);
    else if ((pid = fork()) == 0)
        child_exec(shell, ret, block);
    dup2(stdin_save, STDIN_FILENO);
    dup2(stdout_save, STDOUT_FILENO);
    close(stdout_save);
    close(stdin_save);
    close(pipefd[1]);
    waitpid(pid, &ret->error_code, WNOHANG);
    print_child_error(ret->error_code);
}

void executer_by_fd(shell_t *shell, return_t *ret, block_t *block, int fd)
{
    int com = find_built_in(block->cmd_block[0]);
    int stdin_save = dup(STDIN_FILENO);

    block->fd = WAS_EXEC;
    dup2(fd, STDIN_FILENO);
    if (com != -1)
        built_in[com].func(shell, ret, block);
    else
        create_child(shell, ret, block);
    dup2(stdin_save, STDIN_FILENO);
    close(stdin_save);
}