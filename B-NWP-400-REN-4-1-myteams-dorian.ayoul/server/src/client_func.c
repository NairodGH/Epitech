/*
** EPITECH PROJECT, 2022
** client_func.c
** File description:
** client_func
*/

#include "server.h"

void print_arg(char **arg)
{
    if (!arg) {
        printf("No arg\n");
        return;
    }
    for (size_t i = 0; arg[i] != NULL; i++) {
        printf("%s\n", arg[i]);
    }
}

void print_client(clients_t *list_clients)
{
    for (size_t i = 0; i != MAX_CLIENT; i++) {
        printf("client nb : %ld whit fd : %d id = %s user = %s\n", i,
            list_clients[i].fd, list_clients[i].id,
            list_clients[i].user_name);
    }
}

int get_len_arg(char **arg)
{
    size_t i = 0;

    if (arg == NULL)
        return 0;
    while (arg[i] != NULL)
        i++;
    return i;
}
