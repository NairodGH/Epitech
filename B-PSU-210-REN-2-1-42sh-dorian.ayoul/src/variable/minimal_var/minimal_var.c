/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

static const minimal_var_t base_var[] = {
    {"status", get_status},

    {NULL, NULL}
};

static bool add_min_var(list_t *variable, size_t var_nbr)
{
    list_node_t *temp = NULL;
    variable_t *var_temp = NULL;

    var_temp = base_var[var_nbr].get_minimal_value();
    if (!var_temp)
        return 1;
    temp = create_node((void *)var_temp);
    if (!temp)
        return 1;
    add_node(variable, temp);
    return 0;
}

bool minimal_var(list_t *variable)
{
    list_node_t *temp = NULL;
    variable_t *var_temp = NULL;
    bool as_matched = 0;

    for (size_t i = 0; base_var[i].var; i++, as_matched = 0) {
        foreach(variable->head, temp) {
            var_temp = (variable_t *)temp->data;
            if (!bstrcmp(var_temp->var, base_var[i].var))
                as_matched = 1;
        }
        if (!as_matched && add_min_var(variable, i) == 1)
            return 1;
    }
    return 0;
}
