/*
** EPITECH PROJECT, 2021
** env_exists.c
** File description:
** environment exists?
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>
#include <nep/nstring.h>

bool env_exists(envkey_t **env, char *key)
{
    unsigned int itr;

    if (env == NULL || key == NULL)
        return (false);
    for (itr = 0; env[itr]; ++itr) {
        if (env[itr]->key == NULL)
            continue;
        if (nstrcmp(env[itr]->key, key) == 0)
            return (true);
    }
    return (false);
}