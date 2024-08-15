/*
** EPITECH PROJECT, 2022
** clients.c
** File description:
** clients
*/

#include "server.h"

clients_t *init_client(void)
{
    clients_t *list_clients = malloc(sizeof(clients_t) * MAX_CLIENT);
    messages_t *message = load_message();
    team_t *team = load_team();
    size_t i = 0;

    for (i = 0; i != MAX_CLIENT; i++) {
        list_clients[i].fd = -1;
        list_clients[i].is_login = false;
        list_clients[i].l_message = message;
        list_clients[i].all_team = team;
    }
    load_data(list_clients);
    return list_clients;
}

bool create_client(int fd, lcli_t *list)
{
    uuid_t binuuid;
    lcli_t *tmp = list->head;

    for (list = list->head; list != NULL; list = list->next) {
        if (fd == list->client->fd)
            return false;
    }
    for (list = tmp; list != NULL; list = list->next) {
        if (list->client->fd == -1 && !list->client->id) {
            dprintf(fd, "client connected");
            list->client->fd = fd;
            list->client->id = malloc(UUID_STR_LEN);
            uuid_generate_random(binuuid);
            uuid_unparse(binuuid, list->client->id);
            break;
        }
    }
    return true;
}

void clear_client(lcli_t *list, server_t *serv)
{
    while (list != NULL) {
        if (list->client->id != NULL)
            free(list->client->id);
        if (list->client->user_name != NULL)
            free(list->client->user_name);
        if (serv && list->client->fd != -1 &&
            FD_ISSET(list->client->fd, &serv->writefds)) {
            dprintf(list->client->fd, "100: <client disconnect>");
            close(list->client->fd);
        }
        if (list->prev)
            free(list->prev);
        if (!list->next)
            break;
        list = list->next;
    }
    free(list);
}

void destroy_client(lcli_t *list, int fd)
{
    for (list = list->head; list != NULL; list = list->next) {
        if (list->client->fd == fd) {
            close(fd);
            list->client->fd = -1;
        }
    }
}

lcli_t *get_client(lcli_t *list, int fd)
{
    while (list != NULL) {
        if (list->client->fd == fd) {
            return list;
        }
        list = list->next;
    }
    return NULL;
}
