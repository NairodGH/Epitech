/*
** EPITECH PROJECT, 2021
** update_env.c
** File description:
** Update environment value
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>
#include <nep/nstring.h>

void update_env(envkey_t **env, char *key, char *value)
{
    if (env == NULL || !env_exists(env, key))
        return;

    for (unsigned int itr = 0; env[itr]; ++itr) {
        if (env[itr]->key == NULL)
            return;
        if (nstrcmp(env[itr]->key, key) == 0) {
            env[itr]->value = value;
            return;
        }
    }
}