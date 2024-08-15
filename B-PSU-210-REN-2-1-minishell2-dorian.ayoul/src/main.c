/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main functions for the minishell2 project
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

char **get_command(char *input, char **env)
{
    if (strings_are_identical(input, "exit"))
        my_exit(input);
    else if (strings_are_identical(input, "cd"))
        env = my_cd(input, env);
    else if (strings_are_identical(input, "env"))
        env = my_env(env);
    else if (strings_are_identical(input, "setenv"))
        env = my_setenv(input, env);
    else if (strings_are_identical(input, "unsetenv"))
        env = my_unsetenv(input, env);
    else
        find_bin(input, env);
    return (env);
}

static char **get_commands(char **cmds, char *input)
{
    size_t size = 1;

    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' || input[i] == '|' || input[i] == '>' ||
            input[i] == '<')
            size++;
    }
    cmds = malloc(sizeof(char *) * (size + 1));
    cmds[size] = NULL;
    cmds[0] = strtok(input, ";|<>\n");
    for (size_t i = 1; i != size; i++)
        cmds[i] = strtok(NULL, ";|<>\n");
    return (cmds);
}

static char *get_order(char *order, char *input)
{
    size_t size = 0;

    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' || input[i] == '|' || input[i] == '>' ||
            input[i] == '<')
            size++;
    }
    order = malloc(sizeof(char) * (size + 1));
    order[size] = '\0';
    for (size_t i = 0, j = 0; input[i] != '\0'; i++)
        if (input[i] == ';' || input[i] == '|' || input[i] == '>' ||
            input[i] == '<')
            order[j++] = input[i];
    return (order);
}

static char **parse_and_exec(char *input, char **env)
{
    char *order = get_order(order, input);
    char **cmds = get_commands(cmds, input);

    for (size_t i = 0; cmds[i]; i++) {
        if (order[i] == '|')
            env = pipe_command(cmds, order, env, i);
        else {
            if (!(input = strtok(input, " \n\t"))) return (env);
            env = get_command(cmds[i], env);
        }
        while (order[i] == '|')
            i++;
    }
    free(cmds);
    free(order);
    return (env);
}

int main(int ac, char **av, char **envp)
{
    char *input = NULL;
    char **env = copy_2d(envp, env);

    for (size_t size = 0;;) {
        if (isatty(STDIN_FILENO))
            write(1, ">$ ", 3);
        if (getline(&input, &size, stdin) == -1) {
            if (isatty(STDIN_FILENO)) write(1, "exit\n", 5);
            exit(errno);
        }
        env = parse_and_exec(input, env);
    }
    for (size_t i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    return (0);
}