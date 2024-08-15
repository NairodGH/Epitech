/*
** EPITECH PROJECT, 2021
** executer core
** File description:
** built_in
*/

#include "42sh.h"

static void print_echo_arg(char *arg, return_t *ret)
{
    if (!strcmp(arg, "$?"))
        printf("%d", ret->error_code);
    else
        printf("%s", arg);
}

void echo_func(__attribute__((unused))shell_t *shell,
    return_t *ret, block_t *block)
{
    for (size_t i = 1; block->cmd_block[i]; i++) {
        print_echo_arg(block->cmd_block[i], ret);
        if (i + 1 < barray_len(block->cmd_block))
            printf("%c", ' ');
    }
    printf("%c", '\n');
}
