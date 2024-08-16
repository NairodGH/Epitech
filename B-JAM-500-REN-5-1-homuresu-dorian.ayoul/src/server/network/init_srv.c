#include "server.h"

static int set_srv_opt_udp(server_udp_t *srv)
{
    if (setsockopt(srv->sock, SOL_SOCKET, SO_REUSEADDR, &(int){1},
        sizeof(int)) == -1) {
        printf("Error: setsockopt failed\n");
        return 84;
    }
    srv->addr.sin_family = AF_INET;
    srv->addr.sin_port = htons(srv->port);
    srv->addr.sin_addr.s_addr = INADDR_ANY;
    return 0;
}

static int set_srv_opt_tcp(server_tcp_t *srv)
{
    if (setsockopt(srv->sock, SOL_SOCKET, SO_REUSEADDR, &(int){1},
        sizeof(int)) == -1) {
        printf("Error: setsockopt failed\n");
        return 84;
    }
    srv->addr.sin_family = AF_INET;
    srv->addr.sin_port = htons(srv->port);
    srv->addr.sin_addr.s_addr = INADDR_ANY;
    return 0;
}

int init_server_udp(server_udp_t *server)
{
    server->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (server->sock == -1) {
        printf("Error: UDP Socket creation failed\n");
        return 84;
    }
    if (set_srv_opt_udp(server) != 0)
        return 84;
    if (bind(server->sock, (struct sockaddr *)&server->addr,
        sizeof(server->addr)) == -1) {
        printf("Error: UDP Bind failed\n");
        return 84;
    }
    return 0;
}

int init_server_tcp(server_tcp_t *server)
{
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock == -1) {
        printf("Error: TCP Socket creation failed\n");
        return 84;
    }
    if (set_srv_opt_tcp(server) != 0)
        return 84;
    if (bind(server->sock, (struct sockaddr *)&server->addr,
        sizeof(server->addr)) == -1) {
        printf("Error: TCP Bind failed\n");
        return 84;
    }
    if (listen(server->sock, MAX_CLIENTS) == -1) {
        printf("Error: TCP Listen failed\n");
        close(server->sock);
        return 84;
    }
    return 0;
}