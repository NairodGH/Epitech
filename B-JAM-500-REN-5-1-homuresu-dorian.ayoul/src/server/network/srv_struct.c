#include "server.h"

server_tcp_t *init_srv_struct_tcp()
{
    server_tcp_t *srv = malloc(sizeof(server_tcp_t));

    if (srv == NULL)
        return NULL;
    srv->sock = 0;
    srv->port = DEFAULT_PORT;
    srv->clients = NULL;
    return srv;
}

server_udp_t *init_srv_struct_udp()
{
    server_udp_t *srv = malloc(sizeof(server_udp_t));

    if (srv == NULL)
        return NULL;
    srv->sock = 0;
    srv->port = DEFAULT_PORT;
    return srv;
}

void free_srv_struct_tcp(server_tcp_t *srv)
{
    if (srv == NULL)
        return;
    free_clients(srv->clients);
    free(srv);
}

void free_srv_struct_udp(server_udp_t *srv)
{
    if (srv != NULL)
        free(srv);
}