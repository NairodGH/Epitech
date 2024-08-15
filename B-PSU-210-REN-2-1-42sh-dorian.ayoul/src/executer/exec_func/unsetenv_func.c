/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static void unset(shell_t *shell, block_t *block)
{
    list_node_t *node_temp = shell->env->head;
    list_node_t *next = NULL;
    env_t *env_temp = NULL;

    for (size_t adv = 1; block->cmd_block[adv]; adv++) {
        for (; node_temp; node_temp = next) {
            next = node_temp->next;
            env_temp = (env_t *)node_temp->data;
            if (!strcmp(env_temp->var, block->cmd_block[adv])) {
                remove_node(shell->env, node_temp);
                destroy_node(node_temp, destroy_env);
            }
        }
    }
}

void unsetenv_func(shell_t *shell, return_t *ret, block_t *block)
{
    if (barray_len(block->cmd_block) <= 1) {
        error_command("unsetenv", "Too few arguments");
        ret->error_code = 1;
    }
    else {
        unset(shell, block);
        ret->error_code = 0;
    }
}
