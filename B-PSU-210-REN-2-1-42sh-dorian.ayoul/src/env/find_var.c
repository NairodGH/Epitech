/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

char *get_env_value(char *var, list_t *env)
{
    list_node_t *temp = NULL;
    env_t *data_temp = NULL;

    foreach(env->head, temp) {
        data_temp = (env_t *)temp->data;
        if (!strcmp(var, data_temp->var)) {
            return data_temp->value;
        }
    }
    return NULL;
}

bool replace_env_value(char *var, char *new_value, list_t *env)
{
    list_node_t *temp = NULL;
    env_t *data_temp = NULL;

    foreach(env->head, temp) {
        data_temp = (env_t *)temp->data;
        if (!strcmp(var, data_temp->var)) {
            if (data_temp->value)
                free(data_temp->value);
            data_temp->value = strdup(new_value);
            return 0;
        }
    }
    return 1;
}
