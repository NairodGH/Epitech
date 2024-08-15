/*
** EPITECH PROJECT, 2020
** minishell1.c
** File description:
** 1/3 of 42sh
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include "include/my.h"

int str(char *arr1, char *arr2, int mode)
{
    int nb = 0;

    while (mode == 0 && arr1[nb] != '\0') nb++;
    for (int i = 0; mode == 1 && arr1[i] != '\0'; i++) {
        if (47 < arr1[i] && arr1[i] < 58) nb *= 10, nb += arr1[i] - 48;
        else return (-1);
    }
    if (mode == 2) write(1, arr1, str(arr1, "", 0));
    for (int i = 0; mode == 3 && arr1[i] == arr2[i]; i++) {
        if (arr1[i] == 0 && arr2[i] == 0) return (1);
        if (arr1[i] == 0 && arr2[i] != 0 || arr1[i] != 0 && arr2[i] == 0) break;
    }
    while (mode == 4 && arr1[nb] != 0) arr2[nb++] = arr1[nb];
    return (nb);
}

int execute(struct dirent *sd, char **ae, char *path, char **env)
{
    int i = 0;
    char *temp;

    if (str(ae[0], sd->d_name, 3) || ae[0][0] == '.' && ae[0][1] == '/') {
        temp = malloc(str(path, "", 0) + 1 + str(ae[0], "", 0));
        i = str(path, temp, 4), temp[i++] = '/';
        for (int j = 0; ae[0][j] != 0; j++, i++) temp[i] = ae[0][j];
        if (ae[0][0] == '.' && ae[0][1] == '/') temp = ae[0];
        i = fork(), i == 0 ? i = execve(temp, ae, env) : waitpid(i, &i, 0);
        errno = WEXITSTATUS(i);
        if (WIFSIGNALED(i) && WTERMSIG(i) == SIGSEGV)
            write(1, "Segmentation fault (core dumped)\n", 33), errno = 139;
        return (1);
    }
    return (0);
}

void find_bin(char *ab, char **env, char **ae)
{
    int i = 0;
    char *path;
    DIR *dir;
    struct dirent *sd;

    for (str(ab, ae[i++], 4); ab = strtok(NULL, " \n\t");) str(ab, ae[i++], 4);
    for (ae[i] = NULL, i = 0; !(env[i][0] == 'P' && env[i][1] == 'A');) i++;
    path = malloc(str(env[i], "", 0) - 5);
    for (int j = 5; env[i][j] != 0; j++) path[j - 5] = env[i][j];
    for (path = strtok(path, ":"); path; path = strtok(NULL, ":")) {
        if (access(path, F_OK | R_OK) == -1) continue;
        dir = opendir(path);
        while (sd = readdir(dir)) if (execute(sd, ae, path, env)) return;
        closedir(dir);
    }
    str(ae[0], "", 2), write(1, ": Command not found.\n", 22), errno = 1;
}

int main(int ac, char **av, char **env)
{
    char **set = malloc(sizeof(char *) * 10);
    size_t s;
    int err = 0;

    for (int i = 0; i != 10 && (set[i] = malloc(100)); i++)
        for (int j = 0; j != 100; j++) set[i][j] = '\0';
    for (char **ae = malloc(sizeof(char *) * 10), *ab = NULL;;) {
        for (int i = 0; i != 10; i++) free(ae[i]), ae[i] = malloc(100);
        for (int i = 0; i != 10; i++) for (int j = 0; j != 100;) ae[i][j++] = 0;
        if (isatty(STDIN_FILENO)) str(">$ ", "", 2);
        if (getline(&ab, &s, stdin) == -1)
            (isatty(STDIN_FILENO)) && (write(1, "exit\n", 5)), exit(err);
        if (!(ab = strtok(ab, " \n\t"))) continue;
        str(ab, "exit", 3) ? my_exit(ab) : str(ab, "cd", 3) ?
        my_cd(ab, env) : str(ab, "env", 3) ? my_env(ab, env, set, 0) :
        str(ab, "setenv", 3) ? my_setenv(ab, env, set) : str(ab, "unsetenv", 3)
        ? my_unsetenv(ab, set) : find_bin(ab, env, ae), err = errno;
    }
    return (0);
}