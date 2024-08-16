#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>

#define DEFAULT_PORT 4242
#define MAX_CLIENTS 20

#define BUFFER_SIZE 1024
#define EOF_NETWORK "\r\n"

typedef struct Vector3_s {
    float x;
    float y;
    float z;
} Vector3_t;

typedef struct infoPlayer_s {
    char *name;
    Vector3_t pos;
    Vector3_t dir;
    int life;
    int score;
    int id;
} infoPlayer_t;

typedef struct client_s client_t;
struct client_s
{
    int sock;
    char *ip;
    int port;
    struct sockaddr_in addr;
    client_t *next;
    client_t *prev;
    infoPlayer_t *info;
};

typedef struct server_tcp_s {
    int sock;
    size_t port;
    struct sockaddr_in addr;
    fd_set read_fd;
    fd_set write_fd;
    client_t *clients;
} server_tcp_t;

typedef struct server_udp_s {
    int sock;
    size_t port;
    struct sockaddr_in addr;
    fd_set read_fd;
    fd_set write_fd;
} server_udp_t;

// srv_struct.c
server_tcp_t *init_srv_struct_tcp();
server_udp_t *init_srv_struct_udp();
void free_srv_struct_tcp(server_tcp_t *srv);
void free_srv_struct_udp(server_udp_t *srv);

// add_client.c
client_t *init_clients(int sock);
client_t *add_client(client_t *clients, int sock);

// rm_client.c
void remove_client(client_t *client);
void free_clients(client_t *client);

// init_srv.c
int init_server_tcp(server_tcp_t *server);
int init_server_udp(server_udp_t *server);

// get_packet.c
char *get_tcp_packet(int sock);
char *get_udp_packet(int sock);

// send_packet.c
int send_tcp_packet(int sock, char const *msg, char const *eof);
int send_udp_packet(int sock, char const *msg, char const *eof, client_t *client);
void send_message_to_all_clients(server_tcp_t *server, char *msg);
void send_msg_to_all_cli_exepct_cli(server_tcp_t *server, client_t *client, char *msg);

// action.c
int client_action_mng(server_tcp_t *server, client_t *client, char *msg);

#endif /* !SERVER_H_ */