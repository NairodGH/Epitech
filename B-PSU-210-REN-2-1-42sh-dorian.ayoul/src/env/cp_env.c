/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

static char *get_var_array(char *str)
{
    size_t len = 0;

    for (; str[len] != '='; len++) {
        if (str[len] == '\0') {
            return NULL;
        }
    }
    return bstrndup(str, len);
}

static char *get_env_value_array(char *str)
{
    size_t len = 0;

    for (; str[len] != '='; len++) {
        if (str[len] == '\0') {
            return NULL;
        }
    }
    return bstrdup(str + len + 1);
}

list_t *cp_env(char **env)
{
    list_t *result = create_list();
    list_node_t *node_temp = NULL;
    env_t *env_temp = NULL;

    for (size_t i = 0; env && env[i]; i++) {
        env_temp = bcalloc(sizeof(env_t), 1);
        if (!env_temp)
            return NULL;
        env_temp->var = get_var_array(env[i]);
        env_temp->value = get_env_value_array(env[i]);
        node_temp = create_node((void *)env_temp);
        if (!node_temp)
            return NULL;
        add_node(result, node_temp);
        node_temp = NULL;
        env_temp = NULL;
    }
    return result;
}
