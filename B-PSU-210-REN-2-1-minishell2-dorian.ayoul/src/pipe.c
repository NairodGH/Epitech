/*
** EPITECH PROJECT, 2020
** pipe.c
** File description:
** minishell pipe functions
*/

#include "../lib/my/lib.h"
#include "../include/my.h"

char **pipe_command(char **cmds, char *order, char **env, size_t i)
{
    for (int fd[2], pid, fdd = 0; cmds[i];) {
        if (!(cmds[i] = strtok(cmds[i], " \n\t")) ||
            i > 0 && order[i - 1] != '|')
            return (env);
        pipe(fd);
        if (!(pid = fork())) {
            dup2(fdd, 0);
            if (cmds[i + 1] && order[i] == '|') dup2(fd[1], 1);
            close(fd[0]);
            env = get_command(cmds[i], env);
            exit(1);
        }
        else {
            wait(NULL);
            close(fd[1]);
            fdd = fd[0];
            i++;
        }
    }
    return (env);
}