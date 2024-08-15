/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

void handle_step(ftrace_t *ftrace)
{
    handle_signal(ftrace);
    if (ftrace->ret != -1)
        return;
    if ((long long int)(ftrace->regs->orig_rax) != -1)
        handle_syscall(ftrace);
    else
        handle_call(ftrace);
}

void handle_exit(ftrace_t *ftrace)
{
    ptrace(PTRACE_GETEVENTMSG, ftrace->pid, 0, &ftrace->status);
    ftrace->ret = WEXITSTATUS(ftrace->status);
    fprintf(stderr, "+++ exited with %ld +++\n", ftrace->ret);
}

int ftrace_loop(ftrace_t *ftrace)
{
    waitpid(ftrace->pid, NULL, 0);
    if (ptrace(PTRACE_SETOPTIONS, ftrace->pid, NULL, PTRACE_O_TRACESYSGOOD |
        PTRACE_O_EXITKILL | PTRACE_O_TRACEEXIT) == -1)
        return 84;
    while (1) {
        bzero(ftrace->regs, sizeof(struct user_regs_struct));
        if (ptrace(PTRACE_SINGLESTEP, ftrace->pid, NULL, NULL) == -1)
            return 84;
        waitpid(ftrace->pid, &ftrace->status, 0);
        if (ftrace->status >> 8 == (SIGTRAP | (PTRACE_EVENT_EXIT << 8)))
            handle_exit(ftrace);
        if (ptrace(PTRACE_GETREGS, ftrace->pid, NULL, ftrace->regs) == -1)
            return 84;
        handle_step(ftrace);
        if (ftrace->ret != -1)
            return ftrace->ret;
    }
}
