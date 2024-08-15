/*
** EPITECH PROJECT, 2021
** create_arg_list.c
** File description:
** Create argument list
*/

#include <nep/nmem.h>
#include <nep/nstring.h>
#include <engine.h>
#include <window.h>
#include <stdlib.h>
#include <rpg/args.h>

bool has_arg(list_t *args, char *key)
{
    args_t *arg;

    if (args == NULL)
        return (false);
    list_foreach(args, node) {
        arg = (args_t *) node->value;
        if (nstrcmp(key, arg->key) == 0)
            return (true);
    }
    return (false);
}