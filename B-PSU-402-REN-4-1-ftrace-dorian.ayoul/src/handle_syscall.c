/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

static void print_syscall_param(user_regs_struct_t *regs, syscall_t *syscall)
{
    unsigned long long int ordered_regs[] = {
        regs->rdi,
        regs->rsi,
        regs->rdx,
        regs->r10,
        regs->r8,
        regs->r9
    };

    for (size_t i = 0; i < syscall->arg_num; i++) {
        fprintf(stderr, "0x%llx", ordered_regs[i]);
        if (i != syscall->arg_num - 1)
            fprintf(stderr, ", ");
    }
    fprintf(stderr, ")");
}

void handle_syscall(ftrace_t *ftrace)
{
    syscall_t syscall = {0};

    syscall = get_syscall(ftrace->regs->orig_rax);
    if (syscall.code == -1)
        return;
    fprintf(stderr, "Syscall %s(", syscall.name);
    print_syscall_param(ftrace->regs, &syscall);
    fprintf(stderr, " = 0x%llx\n", ftrace->regs->rax);
}
