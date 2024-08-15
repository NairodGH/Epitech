/*
** EPITECH PROJECT, 2022
** use.c
** File description:
** use
*/

#include "client.h"

int users(char **arg)
{
    size_t i = 0;
    size_t n = 0;
    size_t z = 0;
    char *id = NULL;
    char *name = NULL;
    char *login = NULL;

    while (arg[0][i] != '\0') {
        id = get_user_word(arg[0], &i);
        name = get_user_word(arg[1], &n);
        login = get_user_word(arg[2], &z);
        client_print_users(id, name, atoi(login));
        free(id);
        free(name);
        free(login);
    }
    return 0;
}

int user(char **arg)
{
    client_print_user(arg[0], arg[1], atoi(arg[2]));
    return 0;
}

int subscribe(char **arg)
{
    client_print_subscribed(arg[0], arg[1]);
    return 0;
}

int subscribed(char **arg)
{
    client_print_teams(arg[0], arg[1], arg[2]);
    return 0;
}

int unsubscribe(char **arg)
{
    client_print_unsubscribed(arg[0], arg[1]);
    return 0;
}
