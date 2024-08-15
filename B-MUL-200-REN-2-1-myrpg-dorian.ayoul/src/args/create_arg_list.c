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

void parse_arg(list_t *list, char *arg, char *next_arg)
{
    args_t *args;

    if (arg == NULL || arg[0] != '-')
        return;
    ++arg;
    args = ncalloc(1, sizeof(args_t));
    if (args == NULL)
        return;
    args->key = arg;
    args->value = next_arg;
    list_add(list, args);
}

list_t *create_arg_list(int ac, char **av)
{
    list_t *list = list_create();

    if (list == NULL)
        return (NULL);
    for (int itr = 1; itr < ac; ++itr)
        parse_arg(list, av[itr], av[itr + 1]);
    return (list);
}