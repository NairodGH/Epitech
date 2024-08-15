/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static void unset_var(shell_t *shell, variable_t *variable_temp,
    list_node_t *node_temp)
{
    if (variable_temp->read_only)
        dprintf(STDERR_FILENO, "unset: $%s is read-only.\n",
            variable_temp->var);
    else {
        remove_node(shell->variable, node_temp);
        destroy_node(node_temp, destroy_variable);
    }
}

static void unset(shell_t *shell, block_t *block)
{
    list_node_t *node_temp = shell->variable->head;
    list_node_t *next = NULL;
    variable_t *variable_temp = NULL;

    for (size_t adv = 1; block->cmd_block[adv]; adv++) {
        for (; node_temp; node_temp = next) {
            next = node_temp->next;
            variable_temp = (variable_t *)node_temp->data;
            if (!strcmp(variable_temp->var, block->cmd_block[adv]))
                unset_var(shell, variable_temp, node_temp);
        }
    }
}

void unset_func(shell_t *shell, return_t *ret, block_t *block)
{
    if (barray_len(block->cmd_block) <= 1) {
        error_command("unset", "Too few arguments");
        ret->error_code = 1;
    }
    else {
        unset(shell, block);
        ret->error_code = 0;
    }
}
