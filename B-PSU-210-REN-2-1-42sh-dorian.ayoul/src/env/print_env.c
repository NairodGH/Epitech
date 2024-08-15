/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

void print_env(list_t *env)
{
    list_node_t *node_temp = NULL;
    env_t *env_temp = NULL;

    foreach(env->head, node_temp) {
        env_temp = (env_t *)node_temp->data;
        printf("%s=%s\n", env_temp->var, env_temp->value);
    }
}