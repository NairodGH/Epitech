/*
** EPITECH PROJECT, 2022
** gest_message.c
** File description:
** gest_message
*/

#include "client.h"

void send_message(client_t *client, char *message)
{
    dprintf(client->sockfd, message);
}

void get_message(client_t *client, char *buffer)
{
    read(client->sockfd, buffer, 4096);
}
