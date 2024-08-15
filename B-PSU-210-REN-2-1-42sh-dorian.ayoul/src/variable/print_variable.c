/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

void print_variable(list_t *variable)
{
    list_node_t *node_temp = NULL;
    variable_t *variable_temp = NULL;

    foreach(variable->head, node_temp) {
        variable_temp = (variable_t *)node_temp->data;
        printf("%s\t%s\n", variable_temp->var, variable_temp->value);
    }
}
