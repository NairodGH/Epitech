#include "iencli.h"

client_t *init_struct()
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return NULL;
    client->sock_tcp = 0;
    client->sock_udp = 0;
    client->ip = NULL;
    client->port_tcp = 0;
    client->port_udp = 0;
    return client;
}

void free_memory(client_t *client)
{
    if (client == NULL)
        return;
    if (client->ip != NULL)
        free(client->ip);
    free(client);
}
