/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

static long get_param(ftrace_t *ftrace, size_t rip_val)
{
    long param = ptrace(PTRACE_PEEKDATA, ftrace->pid, rip_val + 1, NULL);

    if (param == -1)
        return 0;
    return param & 0xFFFFFFFF;
}

int call_e8(ftrace_t *ftrace, size_t rip_val)
{
    long offset = get_param(ftrace, rip_val);
    size_t addr = 0;

    if (offset == 0)
        return ERROR;
    addr = rip_val + 5 + offset;
    return enter_func(ftrace, addr);
}
