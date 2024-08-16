#include "iencli.h"

int init_client_tcp(client_t *client)
{
    client->sock_tcp = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock_tcp == -1) {
        printf("Error: Socket creation failed\n");
        return 84;
    }
    client->addr_tcp.sin_family = AF_INET;
    client->addr_tcp.sin_port = htons(client->port_tcp);
    if (inet_pton(AF_INET, client->ip, &client->addr_tcp.sin_addr) == -1) {
        printf("Error: Invalid address\n");
        close(client->sock_tcp);
        return 84;
    }
    if (connect(client->sock_tcp, (struct sockaddr *)&client->addr_tcp,
        sizeof(client->addr_tcp)) == -1) {
        printf("Error: Connection failed\n");
        close(client->sock_tcp);
        return 84;
    }
    return 0;
}

int init_client_udp(client_t *client)
{
    client->sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
    if (client->sock_udp == -1) {
        printf("Error: Socket creation failed\n");
        return 84;
    }
    client->addr_udp.sin_family = AF_INET;
    client->addr_udp.sin_port = htons(client->port_udp);
    if (inet_pton(AF_INET, client->ip, &client->addr_udp.sin_addr) == -1) {
        printf("Error: Invalid address\n");
        close(client->sock_udp);
        return 84;
    }
    return 0;
}