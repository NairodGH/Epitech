/*
** EPITECH PROJECT, 2021
** create_env_list.c
** File description:
** Create environment list
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>

envkey_t **create_env_list(int count)
{
    envkey_t **env;
    int itr = 0;

    if (count < 1)
        return (NULL);
    env = malloc(sizeof(envkey_t) * (count + 1));
    if (env == NULL)
        return (NULL);
    for (; itr < count; ++itr)
        env[itr] = NULL;
    env[itr] = NULL;
    return (env);
}