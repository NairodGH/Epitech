#include "server.h"

static void close_client(client_t *client)
{
    if (client->ip != NULL) {
        if (close(client->sock) == -1)
            printf("Error : Fail to close client %s\n", client->ip);
        printf("-- %s:%i\n", client->ip, client->port);
        free(client->ip);
    } else {
        if (close(client->sock) == -1)
            printf("Error : Fail to close client\n");
        printf("-- ip?:%i\n", client->port);
    }
}

void remove_client(client_t *client)
{
    if (client->prev != NULL && client->next != NULL) {
        client->prev->next = client->next;
        client->next->prev = client->prev;
    } else if (client->prev != NULL && client->next == NULL) {
        client->prev->next = NULL;
    } else if (client->next != NULL && client->prev == NULL) {
        client->next->prev = NULL;
    }
    close_client(client);
    free(client);
}

void free_clients(client_t *client)
{
    client_t *tmp;
    size_t cpt = 0;

    if (client == NULL)
        return;
    tmp = client->next;
    for (; tmp != NULL; tmp = tmp->next, cpt++) {
        close_client(tmp);
        free(tmp->prev);
        if (tmp->next == NULL) {
            free(tmp);
            cpt++;
            break;
        }
    }
    if (cpt == 0)
        free(client);
    printf("%ld client(s) disconnected\n", cpt);
}
