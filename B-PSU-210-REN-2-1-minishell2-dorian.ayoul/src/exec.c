/*
** EPITECH PROJECT, 2020
** exec.c
** File description:
** minishell exec functions
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

static char *get_path(char *path, char *tmp, char **cmd)
{
    size_t i = copy_string(path, tmp);

    tmp[i++] = '/';
    for (size_t j = 0; cmd[0][j] != 0; j++, i++)
        tmp[i] = cmd[0][j];
    tmp[i] = '\0';
    if (cmd[0][0] == '.' && cmd[0][1] == '/')
        tmp = cmd[0];
    return (tmp);
}

static int execute(struct dirent *sd, char **cmd, char *path, char **env)
{
    int i = 0;
    char *tmp;

    if (strings_are_identical(cmd[0], sd->d_name)
        || cmd[0][0] == '.' && cmd[0][1] == '/') {
        tmp = malloc(sizeof(char) *
        (string_length(path) + 1 + string_length(cmd[0]) + 1));
        tmp = get_path(path, tmp, cmd);
        if ((i = fork()) == 0)
            i = execve(tmp, cmd, env);
        else
            waitpid(i, &i, 0);
        if (WIFEXITED(i))
            errno = 0;
        if (WIFSIGNALED(i) && WTERMSIG(i) == SIGSEGV) {
            write(1, "Segmentation fault (core dumped)\n", 33);
            errno = 139;
        }
        return (1);
    }
    return (0);
}

static int get_bin(char **env, char **cmd, size_t i)
{
    size_t j = 0;
    char *path;
    struct dirent *sd;
    DIR *dir;

    path = malloc(sizeof(char) * (string_length(env[i]) - 5 + 1));
    for (; env[i][j + 5] != 0; j++)
        path[j] = env[i][j + 5];
    path[j] = '\0';
    for (path = strtok(path, ":"); path; path = strtok(NULL, ":")) {
        if (access(path, F_OK | R_OK) == -1 || !(dir = opendir(path)))
            continue;
        while (sd = readdir(dir))
            if (execute(sd, cmd, path, env)) return (closedir(dir));
    }
    write(2, cmd[0], string_length(cmd[0]));
    write(2, ": Command not found.\n", 22);
    return (errno = 1);
}

int find_bin(char *input, char **env)
{
    size_t i = 0;
    char **cmd = malloc(sizeof(char *) * 100);

    for (; input; i++, input = strtok(NULL, " \n\t")) {
        cmd[i] = malloc(sizeof(char) * (string_length(input) + 1));
        copy_string(input, cmd[i]);
    }
    for (cmd[i] = NULL, i = 0; !env[i] || !(env[i][0] == 'P' && env[i][1] == 'A'
    && env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '='); i++)
        if (!env[i]) {
            write(2, cmd[0], string_length(cmd[0]));
            write(2, ": Command not found.\n", 21);
            return (errno = 1);
        }
    if (env[i][5] == '\0') {
        write(2, cmd[0], string_length(cmd[0]));
        write(2, ": Command not found.\n", 21);
        return (errno = 1);
    }
    return (get_bin(env, cmd, i));
}