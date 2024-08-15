/*
** EPITECH PROJECT, 2020
** setenv.c
** File description:
** minishell builtin setenv cmd
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

static bool syntax_error(char *input)
{
    if (input[0] < 'A' || input[0] > 'Z' && input[0] < 'a' || input[0] > 'z') {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (errno = 1);
    }
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9' && input[i] < 'A' || input[i] > 'Z'
            && input[i] < 'a' || input[i] > 'z') {
            write(2, "setenv: Variable name must contain", 35);
            write(2, " alphanumeric characters.\n", 26);
            return (errno = 1);
        }
    }
    return (0);
}

static char **increment_2d_size(char **str)
{
    char **tmp = copy_2d(str, tmp);
    size_t size = 0;

    while (str[size])
        free(str[size++]);
    free(str);
    str = malloc(sizeof(char *) * (size + 2));
    for (size_t i = 0; i != size; i++) {
        str[i] = malloc(sizeof(char) * (string_length(tmp[i]) + 1));
        copy_string(tmp[i], str[i]);
        free(tmp[i]);
    }
    free(tmp);
    str[size + 1] = NULL;
    return (str);
}

char *get_var(char *input)
{
    char *name = malloc(sizeof(char) * (string_length(input) + 2));
    char *value;
    size_t i = 0;

    i = copy_string(input, name);
    name[i++] = '=';
    name[i] = '\0';
    if ((input = strtok(NULL, " \n\t"))) {
        value = malloc(sizeof(char) *
        (string_length(name) + string_length(input) + 1));
        i = copy_string(name, value);
        for (size_t j = i; input[i - j] != '\0'; i++)
            value[i] = input[i - j];
        value[i] = '\0';
    }
    else {
        value = malloc(sizeof(char) * (string_length(name) + 1));
        copy_string(name, value);
    }
    free(name);
    return (value);
}

char **set_env(char **env, char *var, size_t i, bool exists)
{
    if (exists) {
        free(env[i]);
        env[i] = malloc(sizeof(char) * (string_length(var) + 1));
        copy_string(var, env[i]);
    }
    else {
        env = increment_2d_size(env);
        env[i + 1] = malloc(sizeof(char) * (string_length(var) + 1));
        copy_string(var, env[i + 1]);
    }
    free(var);
    errno = 0;
    return (env);
}

char **my_setenv(char *input, char **env)
{
    char *var;

    if (!(input = strtok(NULL, " \n\t")))
        return (my_env(env));
    if (syntax_error(input))
        return (env);
    var = get_var(input);
    if (strtok(NULL, " \n\t")) {
        write(2, "setenv: Too many arguments.\n", 28);
        errno = 1;
        return (env);
    }
    for (size_t i = 0; env[i]; i++) {
        for (size_t j = 0; env[i][j] == var[j]; j++)
            if (env[i][j] == '=') return (set_env(env, var, i, true));
        if (!env[i + 1])
            return (set_env(env, var, i, false));
    }
}