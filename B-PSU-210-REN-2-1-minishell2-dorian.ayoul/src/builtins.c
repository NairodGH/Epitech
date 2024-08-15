/*
** EPITECH PROJECT, 2020
** builtins.c
** File description:
** minishell builtins functions
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

void my_exit(char *input)
{
    if (!(input = strtok(NULL, " \n\t"))) {
        if (isatty(STDIN_FILENO))
            write(1, "exit\n", 5);
        exit(0);
    }
    if ((input[0] < '0' || input[0] > '9') || strtok(NULL, " \n\t")) {
        write(2, "exit: Expression Syntax.\n", 25);
        errno = 1;
        return;
    }
    if (get_unsigned(input) == -1) {
        write(2, "exit: Badly formed number.\n", 27);
        errno = 1;
        return;
    }
    exit(get_unsigned(input));
}

char **my_env(char **env)
{
    for (size_t i = 0; env[i]; i++) {
        write(1, env[i], string_length(env[i]));
        write(1, "\n", 1);
    }
    errno = 0;
    return (env);
}

static char **del(char **env, size_t i)
{
    for (; env[i + 1]; i++)
        env[i] = env[i + 1];
    env[i] = NULL;
    return (env);
}

char **my_unsetenv(char *input, char **env)
{
    if (!(input = strtok(NULL, " \n\t"))) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        errno = 1;
        return (env);
    }
    errno = 0;
    for (size_t i = 0; env[i]; i++)
        for (size_t j = 0; env[i][j] == input[j]
            || env[i][j] == '=' && input[j] == '\0'; j++)
            if (env[i][j] == '=' && input[j] == 0) return (env = del(env, i));
    return (env);
}