/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static int error_handling_set(char **cmd_block)
{
    size_t len_cmd = barray_len(cmd_block);

    if (!len_cmd)
        return 1;
    else if (len_cmd == 1)
        return 2;
    else
        return 0;
}

static bool first_letter_valid(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    else {
        error_command("set", "Variable name must begin with a letter");
        return false;
    }
}

static void set(char **cmd_block, list_t *var, return_t *ret)
{
    variable_t *replace = NULL;
    variable_t *temp_var = NULL;
    bool ronly = false;

    for (size_t i = 1; cmd_block[i];) {
        if (!strcmp(cmd_block[i], "-r")) {
            ronly = true;
            i++;
            continue;
        }
        if (!first_letter_valid(cmd_block[i][0])) {
            ret->error_code = 1;
            return;
        }
        replace = get_shell_var(var, cmd_block[i]);
        temp_var = switcher(cmd_block, &i, replace, ronly);
        if (!temp_var)
            return;
        if (!replace) add_node(var, create_node((void *)temp_var));
    }
}

void set_func(shell_t *shell, return_t *ret, block_t *block)
{
    int status = 0;

    status = error_handling_set(block->cmd_block);
    if (status == 1)
        ret->error_code = 1;
    else if (status == 2)
        print_variable(shell->variable);
    else
        set(block->cmd_block, shell->variable, ret);
}
