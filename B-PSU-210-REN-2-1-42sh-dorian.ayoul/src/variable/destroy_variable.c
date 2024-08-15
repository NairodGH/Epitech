/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

void destroy_variable(void *var)
{
    variable_t *var_cast = (variable_t *)var;

    if (!var)
        return;
    if (var_cast->var) {
        free(var_cast->var);
        var_cast->var = NULL;
    }
    if (var_cast->value) {
        free(var_cast->value);
        var_cast->value = NULL;
    }
    if (var_cast->alias) {
        bfree_array(var_cast->alias);
        var_cast->alias = NULL;
    }
}
