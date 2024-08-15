/*
** EPITECH PROJECT, 2022
** split_client.c
** File description:
** split_client
*/

#include "client.h"

client_t *create_client(arg_t *arg)
{
    client_t *client = malloc(sizeof(client_t));

    if (!client)
        return NULL;
    if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed\n");
        exit(0);
    }
    memset(&client->servaddr, 0, sizeof(client->servaddr));
    client->servaddr.sin_family = AF_INET;
    client->servaddr.sin_port = htons(arg->port);
    client->servaddr.sin_addr.s_addr = inet_addr(arg->ip);
    return client;
}
