/*
** EPITECH PROJECT, 2020
** builtins.c
** File description:
** minishell builtins functions
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "include/my.h"

void my_exit(char *ab)
{
    if (!(ab = strtok(NULL, " \n\t")))
        (isatty(STDIN_FILENO)) && (write(1, "exit\n", 5)), exit(0);
    else {
        if ((ab[0] < 48 || ab[0] > 57) || strtok(NULL, " \n\t")) {
            write(1, "exit: Expression Syntax.\n", 25), errno = 1;
            return;
        }
        if (str(ab, "", 1) == -1) {
            write(1, "exit: Badly formed number.\n", 27), errno = 1;
            return;
        }
        exit(str(ab, "", 1));
    }
}

void my_cd(char *ab, char **env)
{
    int i = 0;
    char *path;

    if (!(ab = strtok(NULL, " \n\t")) || ab[0] == '~' && ab[1] == 0) {
        while (!(env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M')) i++;
        path = malloc(str(env[i], "", 0) - 5);
        for (int j = 5; env[i][j] != 0; j++) path[j - 5] = env[i][j];
        chdir(path), free(path);
    }
    if (ab[0] == '.' && ab[1] == 0 && !(errno = 0)) return;
    if (chdir(ab) == -1 && (errno = 1) || strtok(NULL, " \n\t")) {
        if (errno == 0) write(1, "cd: Too many arguments.\n", 25), errno = 1;
        else str(ab, "", 2), write(1, ": No such file or directory.\n", 29);
        return;
    }
    path = getcwd(NULL, 0), i = 0, errno = 0;
    while (!(env[i][0] == 'P' && env[i][1] == 'W' && env[i][2] == 'D')) i++;
    for (int j = 4; env[i][j] != 0; j++) env[i][j] = 0;
    for (int j = 0; path[j] != 0; j++) env[i][j + 4] = path[j];
    free(path);
}

int my_env(char *ab, char **env, char **set, int mode)
{
    for (int i = 0; mode == 0 && env[i] != NULL; i++, errno = 0)
        write(1, env[i], str(env[i], "", 0)), write(1, "\n", 1);
    for (int i = 0; mode == 0 && i != 10; i++)
        if (set[i][0] != 0) str(set[i], "", 2), write(1, "\n", 1);
    if (mode == 1 && (ab[0] < 65 || ab[0] > 90 && ab[0] < 97 || ab[0] > 122)) {
        str("setenv: Variable name must begin with a letter.\n", "", 2);
        return (errno = 1);
    }
    for (int i = 0; mode == 1 && ab[i] != 0; i++)
        if (ab[i] < 48 || ab[i] > 57 && ab[i] < 65 || ab[0] > 90 && ab[0] < 97
            || ab[0] > 122) {
            str("setenv: Variable name must contain alphanumeric characters.\n",
            "", 2);
            return (errno = 1);
        }
    if (mode == 2 && strtok(NULL, " \n\t")) {
        write(1, "setenv: Too many arguments.\n", 28);
        return (errno = 1);
    }
    return (0);
}

void my_setenv(char *ab, char **env, char **set)
{
    if (!(ab = strtok(NULL, " \n\t")) && !(errno = 0)) my_env(ab, env, set, 0);
    for (int i = 0, k = 0; ab != NULL && i != 10; i++, k = 0) {
        if (my_env(ab, env, set, 1)) return;
        if (set[i][0] == 0) {
            for (int j = 0; ab[j] != 0;) set[i][k++] = ab[j++], errno = 0;
            if ((set[i][k++] = '=') && !(ab = strtok(NULL, " \n\t"))) break;
            if (my_env(ab, env, set, 2)) return;
            for (int j = 0; ab[j] != 0;) set[i][k++] = ab[j++];
            break;
        }
        if (my_env(ab, env, set, 2)) return;
        while (set[i][k] == ab[k]) k++, errno = 0;
        if (set[i][k] == '=' && ab[k] == 0) {
            for (ab = strtok(NULL, " \n\t"); set[i][++k] != 0;) set[i][k] = 0;
            if (ab == NULL) break;
            while (set[i][k] != '=') k--;
            for (int j = 0; ab[j] != 0;) set[i][++k] = ab[j++];
            break;
        }
    }
}

void my_unsetenv(char *ab, char **set)
{
    if (!(ab = strtok(NULL, " \n\t"))) {
        write(1, "unsetenv: Too few arguments.\n", 29), errno = 1;
        return;
    }
    for (int i = 0, k = 0; i != 10; i++, k = 0) {
        while (set[i][k] == ab[k]) k++, errno = 0;
        if (set[i][k] == '=' && ab[k] == 0)
            for (k = 0; set[i][k] != 0;) set[i][k++] = 0;
    }
}