/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

static char *filter_program_name(char *name)
{
    char *new_name = NULL;

    for (size_t i = 0; name[i] != '\0'; i++) {
        if (strncmp(&name[i], "./", 2) == 0) {
            new_name = strdup(&name[i + 2]);
        }
    }
    if (new_name == NULL)
        new_name = strdup(name);
    return new_name;
}

pid_t ftrace_exec_prog(char *fileName, char **argv)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror(strerror(errno));
        return -1;
    }
    if (pid == 0) {
        if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1 ||
                            execvp(fileName, argv) == -1) {
            perror(strerror(errno));
            raise(SIGSTOP);
        }
    }
    return pid;
}

int ftrace(args_t *args)
{
    ftrace_t *ftrace = create_ftrace();
    int ret = 0;

    if (!ftrace)
        return 84;
    if (args->fileName != NULL) {
        ftrace->name = filter_program_name(args->fileName);
        ftrace->pid = ftrace_exec_prog(args->fileName, args->argv);
    }
    if (ftrace->pid == -1)
        return 84;
    ret = ftrace_loop(ftrace);
    destroy_ftrace(ftrace);
    return ret;
}
