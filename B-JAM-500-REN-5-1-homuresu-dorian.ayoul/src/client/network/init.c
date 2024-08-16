#include "iencli.h"

static int init_client(client_t *client, char *ip, int port)
{
    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock == -1) {
        printf("Error: Socket creation failed\n");
        return 84;
    }
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &client->addr.sin_addr) == -1) {
        printf("Error: Invalid address\n");
        close(client->sock);
        return 84;
    }
    //! DESACTIVATE TO GET UDP
    if (connect(client->sock, (struct sockaddr *)&client->addr,
        sizeof(client->addr)) == -1) {
        printf("Error: Connection failed\n");
        close(client->sock);
        return 84;
    }
    return 0;
}

int client_manage(char *ip, int port, client_t *client)
{
    int check = 1;
    client = init_struct();

    if (client == NULL)
        return 84;
    if (init_client(client, ip, port) != 0) {
        free_memory(client);
        return 84;
    }
    printf("Client connected to %s:%i\n", ip, port);
    while (check == 1)
        check = select_manage(client);
    close(client->sock);
    free_memory(client);
    return check;
}
