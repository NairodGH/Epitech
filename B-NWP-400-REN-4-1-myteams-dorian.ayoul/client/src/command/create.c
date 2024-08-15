/*
** EPITECH PROJECT, 2022
** create.c
** File description:
** create
*/

#include "client.h"

int help(char **arg)
{
    printf("%s\n", arg[0]);
    return 0;
}

int create(char **arg)
{
    if (strcmp(arg[0], "team") == 0)
        client_print_team_created(arg[1], arg[2], arg[3]);
    if (strcmp(arg[0], "channel") == 0)
        client_print_channel_created(arg[1], arg[2], arg[3]);
    if (strcmp(arg[0], "thread") == 0)
        client_print_thread_created(
            arg[1], arg[2], (unsigned long)(atol(arg[3])), arg[4], arg[5]);
    if (strcmp(arg[0], "reply") == 0)
        client_print_reply_created(
            arg[1], arg[2], (unsigned long)(atol(arg[3])), arg[4]);
    return 0;
}
