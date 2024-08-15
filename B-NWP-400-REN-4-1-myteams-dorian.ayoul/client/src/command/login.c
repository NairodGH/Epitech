/*
** EPITECH PROJECT, 2022
** login.c
** File description:
** login
*/

#include "client.h"

int login(char **arg)
{
    if (get_len_arg(arg) < 2)
        return 1;
    client_event_logged_in(arg[0], arg[1]);
    return 0;
}

int logout(char **arg)
{
    if (get_len_arg(arg) < 2)
        return 1;
    client_event_logged_out(arg[0], arg[1]);
    return 0;
}

int my_send(char **arg)
{
    if (arg)
        client_event_private_message_received(arg[0], arg[1]);
    printf("Message reçu %s\n", arg[1]);
    return 0;
}

int messages(char **arg)
{
    size_t i = 0;
    size_t n = 0;
    size_t z = 0;
    char *sender = NULL;
    char *time = NULL;
    char *mess = NULL;

    while (arg[0][i] != '\0') {
        sender = get_user_word(arg[0], &i);
        time = get_user_word(arg[1], &n);
        mess = get_user_word(arg[2], &z);
        client_private_message_print_messages(sender, (time_t)atol(time), mess);
        free(sender);
        free(time);
        free(mess);
    }
    return 0;
}
