/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

void destroy_env(void *data)
{
    env_t *data_env = (env_t *)data;

    if (!data_env)
        return;
    if (data_env->var)
        free(data_env->var);
    if (data_env->value)
        free(data_env->value);
}