/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main
*/

#include "42sh.h"

static const minimal_env_t base_var[] = {
    {"PATH", get_path},
    {"SHLVL", get_shlvl},
    {"PWD", get_pwd},
    {"OLDPWD", get_oldpwd},
    {"HOME", get_home},

    {NULL, NULL}
};

static bool add_min_env(list_t *env, size_t var_nbr)
{
    list_node_t *temp = NULL;
    env_t *var_temp = NULL;

    var_temp = base_var[var_nbr].get_minimal_value();
    if (!var_temp)
        return 1;
    temp = create_node((void *)var_temp);
    if (!temp)
        return 1;
    add_node(env, temp);
    return 0;
}

bool minimal_env(list_t *env)
{
    list_node_t *temp = NULL;
    env_t *env_temp = NULL;
    bool as_matched = 0;

    for (size_t i = 0; base_var[i].var; i++, as_matched = 0) {
        foreach(env->head, temp) {
            env_temp = (env_t *)temp->data;
            if (!bstrcmp(env_temp->var, base_var[i].var))
                as_matched = 1;
        }
        if (!as_matched && add_min_env(env, i) == 1)
            return 1;
    }
    return 0;
}
