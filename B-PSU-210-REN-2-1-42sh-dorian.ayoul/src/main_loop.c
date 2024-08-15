/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

static void prompt(list_t *env, bool is_tty)
{
    if (is_tty)
        bprintf("\e[31m%s\e[0m--> ", get_env_value("PWD", env));
}

static char *read_line(bool is_tty, return_t *ret)
{
    char *readed = NULL;
    size_t read_len = 0;

    if (getline(&readed, &read_len, stdin) == EOF) {
        ret->error_code %= 256;
        if (is_tty)
            bprintf("exit\n");
        if (readed)
            free(readed);
        return NULL;
    }
    return readed;
}

static void destroy_temp_elems(list_t *parsing, char *readed)
{
    if (parsing)
        destroy_list(parsing, destroy_elem_block);
    if (readed)
        free(readed);
}

int main_loop(shell_t *shell, bool is_tty, return_t *ret)
{
    char *readed = NULL;

    while (!ret->is_exited) {
        prompt(shell->env, is_tty);
        readed = read_line(is_tty, ret);
        readed = check_var_buf(shell, ret, readed);
        readed = set_coma(readed);
        shell->parsing = parser(readed, ret);
        if (readed == NULL || shell->parsing == NULL || !shell->parsing->lenght
            || verif_block(shell, ret))
            continue;
        ret->error_code = 0;
        resolver(shell, ret);
        destroy_temp_elems(shell->parsing, readed);
        readed = NULL;
        shell->parsing = NULL;
    }
    if (readed)
        free(readed);
    return ret->error_code;
}
