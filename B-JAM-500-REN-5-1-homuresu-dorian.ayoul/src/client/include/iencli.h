#ifndef IENCLI_H_
#define IENCLI_H_

#include "includes.h"
#ifndef _WIN32
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define EOF_NETWORK "\r\n"

typedef struct client_s {
  char *ip;
  int port_tcp;
  int port_udp;
  int sock_tcp;
  int sock_udp;
  struct sockaddr_in addr_tcp;
  struct sockaddr_in addr_udp;
  fd_set read_fd;
  fd_set write_fd;
} client_t;

// memory.c
client_t *init_struct();
void free_memory(client_t *client);

// network/init_cli.c
int init_client_udp(client_t *client);
int init_client_tcp(client_t *client);

// network/get_packet.c
char *get_tcp_packet(int sock);
char *get_udp_packet(int sock);

// network/send_packet.c
int send_tcp_packet(int sock, char const *msg, char const *eof);
int send_udp_packet(int sock, char const *msg, char const *eof, client_t *client);

// manage.c
int manage_tcp_recv_actions(client_t *client, game_t *game);
int manage_udp_recv_actions(client_t *client);
int manage_tcp_send_actions(client_t *client);
int manage_udp_send_actions(client_t *client);

// client.c
int loop_client(client_t *client, game_t *game);

// action.c
int client_action_mng(client_t *client, game_t *game, char *msg);
#endif
#endif /* !IENCLI_H_ */