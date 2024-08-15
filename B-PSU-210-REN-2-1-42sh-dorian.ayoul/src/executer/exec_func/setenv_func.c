/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static int error_handling_setenv(char **cmd_block, list_t *env)
{
    size_t len_cmd = barray_len(cmd_block);

    if (!cmd_block) {
        error_command("setenv", "Try again");
        return 1;
    }
    if (len_cmd > 3) {
        error_command("setenv", "Too many arguments");
        return 1;
    }
    if (len_cmd == 1) {
        print_env(env);
        return 1;
    }
    return 0;
}

static int setenv_new_var(char **cmd_block, list_t *env)
{
    env_t *temp = create_env(cmd_block[1], cmd_block[2]);
    list_node_t *node_temp = create_node((void *)temp);

    if (!temp || !node_temp)
        return 1;
    add_node(env, node_temp);
    return 0;
}

static void setenv_end(shell_t *shell, return_t *ret, block_t *block)
{
    if (setenv_new_var(block->cmd_block, shell->env)) {
        ret->is_exited = 1;
    }
}

void setenv_func(shell_t *shell, return_t *ret, block_t *block)
{
    if (error_handling_setenv(block->cmd_block, shell->env)) {
        ret->error_code = 1;
    }
    else if (!replace_env_value(block->cmd_block[1], block->cmd_block[2],
        shell->env)) {
        ret->error_code = 0;
    }
    else
        setenv_end(shell, ret, block);
}
