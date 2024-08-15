/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** child_error
*/

#include "42sh.h"

static void print_child_signal(int status)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) != 1) {
        if (WCOREDUMP(status))
            dprintf(STDERR_FILENO, "%s (core dumped)\n", strsignal(
            WTERMSIG(status)));
        else
            dprintf(STDERR_FILENO, "%s\n", strsignal(status));
    }
}

void print_child_error(int status)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == 8) {
        if (WCOREDUMP(status))
            dprintf(STDERR_FILENO, "Floating exception (core dumped)\n");
        else
            dprintf(STDERR_FILENO, "Floating exception\n");
        return;
    }
    print_child_signal(status);
}
