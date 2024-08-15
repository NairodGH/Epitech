/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

env_t *create_env(char *variable, char *value)
{
    env_t *result = bcalloc(sizeof(env_t), 1);

    if (!result)
        return NULL;
    if (variable)
        result->var = bstrdup(variable);
    if (value)
        result->value = bstrdup(value);
    return result;
}