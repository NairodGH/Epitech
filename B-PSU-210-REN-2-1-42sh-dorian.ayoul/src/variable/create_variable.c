/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

variable_t *create_variable(char *variable, char *value, bool read_only)
{
    variable_t *result = calloc(sizeof(variable_t), 1);

    if (result) {
        result->var = variable;
        result->value = value;
        result->read_only = read_only;
        result->alias = binit_array_light(0);
        if (!result->alias) {
            free(result);
            return NULL;
        }
    }
    return result;
}
