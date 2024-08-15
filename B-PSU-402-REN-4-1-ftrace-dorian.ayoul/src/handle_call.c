/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

static const call_array_t calls_list[] = {
    {0xe8, call_e8},
    {0xff, call_ff},
    {0xc2, all_returns},
    {0xc3, all_returns},
    {0xca, all_returns},
    {0xcb, all_returns},
};

size_t filter_param(size_t param, size_t nbr_params)
{
    size_t res = 0;
    size_t filter = 0xff;

    for (size_t i = 0; (param & filter) != filter && i < nbr_params;
                                                i++, filter <<= 8) {
        res |= param & filter;
    }
    return res;
}

void handle_call(ftrace_t *ftrace)
{
    size_t ret = ptrace(PTRACE_PEEKTEXT, ftrace->pid, ftrace->regs->rip);

    for (size_t i = 0; i < sizeof(calls_list) / sizeof(call_array_t); i++) {
        if ((ret & 0xff) == calls_list[i].code) {
            calls_list[i].function(ftrace, ftrace->regs->rip);
            return;
        }
    }
}
