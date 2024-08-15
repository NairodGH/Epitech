/*
** EPITECH PROJECT, 2020
** cd.c
** File description:
** minishell builtin cd cmd
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

static char **create_wd_env(char **env, char *wd, bool old)
{
    char *cmd;
    size_t i = 0;
    size_t j = 0;

    cmd = malloc(sizeof(char) * ((old ? 14 : 11) + string_length(wd) + 1));
    i = copy_string((old ? "setenv OLDPWD " : "setenv PWD "), cmd);
    for (; wd[j] != '\0'; j++)
        cmd[i + j] = wd[j];
    cmd[i + j] = '\0';
    env = my_setenv(cmd = strtok(cmd, " \n\t"), env);
    free(cmd);
    free(wd);
    return (env);
}

static char **set_wd(char **env, char *wd, bool old)
{
    size_t i = 0;
    size_t j = 0;

    for (; old && !(env[i][0] == 'O' && env[i][1] == 'L' &&
    env[i][2] == 'D' && env[i][2] == 'P' && env[i][3] == 'W' && env[i][4] == 'D'
    && env[i][5] == '=') || !old && !(env[i][0] == 'P' && env[i][1] == 'W'
    && env[i][2] == 'D' && env[i][3] == '='); i++)
        if (!env[i + 1])
            return (env = create_wd_env(env, wd, old));
    free(env[i]);
    env[i] = malloc(sizeof(char) * ((old ? 7 : 4) + string_length(wd) + 1));
    j = copy_string((old ? "OLDPWD=" : "PWD="), env[i]);
    for (; wd[j - (old ? 7 : 4)] != '\0'; j++)
        env[i][j] = wd[j - (old ? 7 : 4)];
    env[i][j] = '\0';
    free(wd);
    return (env);
}

static char **cd_oldpwd(char **env, char *oldpwd, size_t i, size_t j)
{
    char *path;

    for (; !(env[i][0] == 'O' && env[i][1] == 'L' && env[i][2] == 'D' &&
    env[i][3] == 'P' && env[i][4] == 'W' && env[i][5] == 'D'
    && env[i][6] == '='); i++)
        if (!env[i + 1] && (errno = 1)) {
            write(2, ": No such file or directory.\n", 29);
            return (env);
        }
    path = malloc(sizeof(char) * (string_length(env[i]) - 7 + 1));
    for (; env[i][j + 7] != '\0'; j++)
        path[j] = env[i][j + 7];
    path[j] = '\0';
    if (chdir(path) == -1 && (errno = 1)) {
        write(2, ": No such file or directory.\n", 29);
        free(path);
        return (env);
    }
    free(path);
    errno = 0;
    return (env = set_wd(env, oldpwd, 1));
}

static char **cd_home(char **env, char *oldpwd)
{
    char *path;
    size_t i = 0;
    size_t j = 0;

    for (; !(env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M'
    && env[i][3] == 'E' && env[i][4] == '='); i++)
        if (!env[i + 1])
            return (env);
    if (env[i][5] == '\0')
        return (env);
    path = malloc(sizeof(char) * (string_length(env[i]) - 5 + 1));
    for (; env[i][j + 5] != '\0'; j++)
        path[j] = env[i][j + 5];
    path[j] = '\0';
    if (chdir(path) == -1 && (errno = 1)) {
        write(2, "cd: Can't change to home directory.\n", 36);
        return (env);
    }
    free(path);
    errno = 0;
    return (env = set_wd(env, oldpwd, 1));
}

char **my_cd(char *input, char **env)
{
    char *oldpwd = getcwd(NULL, 0);

    if (!(input = strtok(NULL, " \n\t"))) {
        env = cd_home(env, oldpwd);
        return (env = set_wd(env, getcwd(NULL, 0), 0));
    }
    if (strtok(NULL, " \n\t") && (errno = 1)) {
        write(2, "cd: Too many arguments.\n", 25);
        return (env);
    }
    if (input[0] == '-' && input[1] == '\0') {
        env = cd_oldpwd(env, oldpwd, 0, 0);
        return (env = set_wd(env, getcwd(NULL, 0), 0));
    }
    if (chdir(input) == -1 && (errno = 1)) {
        write(2, input, string_length(input));
        write(2, ": No such file or directory.\n", 29);
        return (env);
    }
    env = set_wd(env, oldpwd, 1);
    return (env = set_wd(env, getcwd(NULL, 0), errno = 0));
}