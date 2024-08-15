/*
** EPITECH PROJECT, 2021
** utils for set func
** File description:
** set_utils
*/

#include "42sh.h"

variable_t *new_var(char **block, size_t *i, bool ronly)
{
    variable_t *variable = create_variable(NULL, NULL, false);

    if (equal_is_next(block[(*i) + 1])) {
        variable->var = strdup(block[*i]);
        (*i) = hook_set_value(block[(*i) + 2], variable, *i);
    }
    else if (contain_equal(block[*i])) {
        variable->var = copy_from_to(block[*i], 0, '=');
        variable->value = copy_from_to(block[*i], '=', 0);
        (*i)++;
    }
    else {
        variable->var = strdup(block[*i]);
        variable->value = strdup("\0");
        (*i)++;
    }
    if (!variable->value || !variable->var)
        return NULL;
    variable->read_only = ronly;
    return variable;
}

variable_t *replace_var(char **block, size_t *i, variable_t *to_replace, bool r)
{
    if (to_replace->read_only) {
        dprintf(STDERR_FILENO, "set: $%s is read-only.\n", to_replace->var);
        return NULL;
    }
    free(to_replace->value);
    if (equal_is_next(block[(*i) + 1]))
        (*i) = hook_set_value(block[(*i) + 2], to_replace, *i);
    else if (contain_equal(block[*i])) {
        to_replace->value = copy_from_to(block[*i], '=', 0);
        (*i)++;
    }
    else {
        to_replace->value = strdup("\0");
        (*i)++;
    }
    if (!to_replace->value || !to_replace->var)
        return NULL;
    to_replace->read_only = r;
    return to_replace;
}

variable_t *switcher(char **block, size_t *i, variable_t *replace, bool ronly)
{
    variable_t *new = NULL;

    if (!replace)
        new = new_var(block, i, ronly);
    else
        new = replace_var(block, i, replace, ronly);
    return new;
}