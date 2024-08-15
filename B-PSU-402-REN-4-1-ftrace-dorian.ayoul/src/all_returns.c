/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

int all_returns(ftrace_t *ftrace, UNUSED size_t rip_val)
{
    node_t *node = pop_list(ftrace->stack);

    if (!node)
        return ERROR;
    fprintf(stderr, "Leaving function %s\n", (char *)node->data);
    destroy_node(node, ftrace->stack->free_data);
    return SUCCESS;
}
