#include "server.h"

client_t *init_clients(int sock)
{
    client_t *clients = malloc(sizeof(client_t));

    if (clients == NULL)
        return NULL;
    clients->sock = sock;
    clients->ip = NULL;
    clients->port = 0;
    clients->next = NULL;
    clients->prev = NULL;
    return clients;
}

client_t *add_client(client_t *clients, int sock)
{
    struct sockaddr_in addr;
    socklen_t addr_size = sizeof(struct sockaddr_in);
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        return NULL;
    if (getpeername(sock, (struct sockaddr *)&addr, &addr_size) == -1) {
        printf("Error : Fail to get client address\n");
        return NULL;
    }
    for (; clients->next != NULL; clients = clients->next);
    new_client->sock = sock;
    new_client->ip = strdup(inet_ntoa(addr.sin_addr));
    new_client->port = ntohs(addr.sin_port);
    new_client->next = NULL;
    new_client->prev = clients;
    clients->next = new_client;
    return new_client;
}
