/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

static void free_map(client_t *client)
{
    size_t max_y = client->size_map.y;
    size_t max_x = client->size_map.x;

    for (size_t y = 0; y < max_y; y++) {
        for (size_t x = 0; x < max_x; x++) {
            free(client->map[y][x].inv);
            list_destroy(client->map[y][x].player, NULL);
        }
        free(client->map[y]);
    }
    free(client->map);
}

void free_client(client_t *client)
{
    close(client->socket->fd);
    shutdown(client->socket->fd, SHUT_RDWR);
    free(client->socket->addr);
    free(client->socket);
    if (client->map)
        free_map(client);
    list_destroy(client->command, (void (*)(void *))nlib_command_destroy);
    list_destroy(client->pending_commands, free);
    list_destroy(client->player, NULL);
    list_destroy(client->team, free);
    if (client->win_team)
        free(client->win_team);
    free(client->uuid);
    free(client);
}

static void split_create_client(client_t *client, arg_t *arg)
{
    client->socket->addr->sin_family = AF_INET;
    client->socket->addr->sin_port = htons(arg->port);
    client->socket->addr->sin_addr.s_addr = inet_addr(arg->machine);
    client->size_map.x = -1;
    client->size_map.y = -1;
    client->time_unit = 0;
    client->map = NULL;
}

client_t *create_client(arg_t *arg)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client || !(client->socket = malloc(sizeof(socket_t))))
        return NULL;
    client->socket->addr = calloc(1, sizeof(sockaddr_in_t));
    if ((client->socket->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "%s[ERROR]%s socket creation failed\n", R, W);
        exit(ERROR_EXIT);
    }
    if (!(client->command = list_create()) ||
        !(client->pending_commands = list_create()))
        return NULL;
    if (!(client->player = list_create()) || !(client->team = list_create()))
        return NULL;
    split_create_client(client, arg);
    return client;
}
