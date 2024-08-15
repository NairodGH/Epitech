/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

ftrace_t *create_ftrace(void)
{
    ftrace_t *ftrace = calloc(1, sizeof(ftrace_t));

    if (!ftrace)
        return NULL;
    ftrace->stack = create_linked_list();
    if (!ftrace->stack)
        return NULL;
    ftrace->stack->free_data = destroy_string;
    ftrace->regs = calloc(1, sizeof(user_regs_struct_t));
    if (!ftrace->regs)
        return NULL;
    ftrace->pid = -1;
    ftrace->status = -1;
    ftrace->ret = -1;
    return ftrace;
}

void destroy_ftrace(ftrace_t *ftrace)
{
    if (!ftrace)
        return;
    destroy_linked_list(ftrace->stack);
    free(ftrace->name);
    free(ftrace->regs);
    free(ftrace);
}
