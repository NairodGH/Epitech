/*
** EPITECH PROJECT, 2021
** create_env_key.c
** File description:
** Create environment key
*/

#include <stddef.h>
#include <stdlib.h>
#include <envdata.h>

envkey_t *create_env_key(char *key, char *value)
{
    envkey_t *env = malloc(sizeof(envkey_t));

    if (env == NULL)
        return (NULL);
    env->key = key;
    env->value = value;
    return (env);
}