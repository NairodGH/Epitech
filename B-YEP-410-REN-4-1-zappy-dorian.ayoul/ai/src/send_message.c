/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message ai
*/

#include "zappy_ai.h"

char *remove_new_line(char *str)
{
    char *new_str = NULL;
    size_t i = 0;

    while (str[i] != '\0' && str[i] != '\n')
        i++;
    new_str = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (str[i] != '\0' && str[i] != '\n') {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';
    return new_str;
}

bool send_message(list_t *pending, list_t *list, socket_t *socket, char *mess)
{
    command_t *command = nlib_command_create(strdup(mess));
    char *mess_send = NULL;

    if (!command)
        return false;
    if (list_push_data(command->socks, socket) == -1)
        return false;
    if (list_push_data(list, command) == -1)
        return false;
    if (pending && list_push_data(pending, strdup(mess)) == -1)
        return false;
    mess_send = remove_new_line(mess);
    printf("%s[INFO]%s message send [%s] to fd [%d]\n", G, W, mess_send,
        ((socket_t *)((command_t *)list->head->data)->socks->head->data)->fd);
    free(mess_send);
    return true;
}
