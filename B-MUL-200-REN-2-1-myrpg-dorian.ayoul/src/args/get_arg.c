/*
** EPITECH PROJECT, 2021
** get_arg.c
** File description:
** Get argument
*/

#include <nep/nmem.h>
#include <nep/nstring.h>
#include <engine.h>
#include <window.h>
#include <stdlib.h>
#include <rpg/args.h>

char *get_arg(list_t *args, char *key)
{
    args_t *arg;

    if (args == NULL)
        return (false);
    list_foreach(args, node) {
        arg = (args_t *) node->value;
        if (nstrcmp(key, arg->key) == 0)
            return (arg->value);
    }
    return (NULL);
}