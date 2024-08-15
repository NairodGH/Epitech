/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

char *get_var_value(list_t *variable, char *var)
{
    list_node_t *node_temp = NULL;
    variable_t *var_temp = NULL;

    foreach(variable->head, node_temp) {
        var_temp = (variable_t *)node_temp->data;
        if (!strcmp(var, var_temp->var))
            return var_temp->value;
        for (size_t adv = 0; var_temp->alias[adv]; adv++)
            if (!strcmp(var, var_temp->alias[adv]))
                return var_temp->value;
    }
    return NULL;
}

variable_t *get_shell_var(list_t *var, char *name)
{
    list_node_t *temp_node = NULL;
    variable_t *temp_cast = NULL;
    char *temp_name = NULL;

    if (contain_equal(name))
        temp_name = copy_from_to(name, 0, '=');
    else
        temp_name = strdup(name);
    foreach(var->head, temp_node) {
        temp_cast = (variable_t *)temp_node->data;
        if (!strcmp(temp_cast->var, temp_name)) {
            free(temp_name);
            return temp_cast;
        }
    }
    free(temp_name);
    return NULL;
}
