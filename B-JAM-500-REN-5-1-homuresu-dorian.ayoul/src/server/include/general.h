#ifndef GENERAL_H_
#define GENERAL_H_

#include "server.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>

typedef struct homuresu_s {
    server_tcp_t *srv_tcp;
    server_udp_t *srv_udp;
} homuresu_t;

// general.c
void free_gn_struct(homuresu_t *gn);

// server.c
int loop_server(homuresu_t *gn);

// cli_accept.c
int client_action_manage(server_tcp_t *server);
int assign_fd_connection(server_tcp_t *server, int con_fd);
int check_client_connected(homuresu_t *gn);

// manage.c
int manage_tcp_recv_actions(server_tcp_t *server, client_t *client);
int manage_udp_recv_actions(server_udp_t *server, client_t *client);

#endif /* !GENERAL_H_ */