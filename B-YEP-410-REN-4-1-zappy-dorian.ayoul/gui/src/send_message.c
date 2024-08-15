/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message gui
*/

#include "zappy_gui.h"

bool send_message(list_t *pending, list_t *list, socket_t *socket, char *mess)
{
    command_t *command = nlib_command_create(strdup(mess));

    if (!command)
        return false;
    if (list_push_data(command->socks, socket) == -1)
        return false;
    if (list_push_data(list, command) == -1)
        return false;
    if (pending && list_push_data(pending, strdup(mess)) == -1)
        return false;
    return true;
}
