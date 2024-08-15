/*
** EPITECH PROJECT, 2022
** error.c
** File description:
** error
*/

#include "client.h"

int unknown_user(char **arg)
{
    client_error_unknown_user(arg[0]);
    return 0;
}

int unauthorized(__attribute__((unused)) char **arg)
{
    client_error_unauthorized();
    return 0;
}
