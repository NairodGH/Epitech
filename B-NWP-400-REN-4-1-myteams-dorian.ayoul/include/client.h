/*
** EPITECH PROJECT, 2022
** client.h
** File description:
** client
*/

#ifndef CLIENT_H
    #define CLIENT_H
    #include "logging_client.h"
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <stdbool.h>
    #include "nlib.h"

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define MAX_CLIENT 10

typedef struct arg_s {
    char *ip;
    int port;
} arg_t;

typedef struct client_s {
    char *user_name;
    size_t user_uuid;
    size_t team_uuid;
    size_t channel_uuid;
    size_t thread_uuid;
    int sockfd;
    bool is_login;
    struct sockaddr_in servaddr;
    fd_set readfds;
    fd_set writefds;
} client_t;

int unknown_user(char **arg);
int unauthorized(char **arg);
int help(char **arg);
int users(char **arg);
int user(char **arg);
int login(char **arg);
int logout(char **arg);
int my_send(char **arg);
int messages(char **arg);
int subscribe(char **arg);
int subscribed(char **arg);
int unsubscribe(char **arg);
int create(char **arg);

typedef struct map_s {
    const char *cmd;
    int (*func_ptr)(char **arg);
} map_t;

static const map_t com[] =
{
    {"501\0", &unknown_user},
    {"502\0", &unauthorized},
    {"200\0", &help},
    {"207\0", &users},
    {"206\0", &user},
    {"201\0", &login},
    {"202\0", &logout},
    {"203\0", &my_send},
    {"204\0", &messages},
    {"208\0", &subscribe},
    {"209\0", &subscribed},
    {"210\0", &unsubscribe},
    {"211\0", &create},
    {NULL, NULL}
};

// Function :
void sig_handler_c(int signum);

int init_client(arg_t *arg);
bool loop_client(client_t *client);
client_t *create_client(arg_t *arg);

void send_message(client_t *client, char *message);
void get_message(client_t *client, char *buffer);
bool send_message_buff(client_t *client, char *message);
void parse_return(char *buffer);
bool get_one_word(char *message, char *arg, size_t *i, size_t *s);
char *recup_arg(char *message, size_t *i);

char *get_inputs(char **current, bool *first);
int get_len_arg(char **arg);
void print_arg(char **arg);
char **create_arg(char *str);
char *get_user_word(char *str, size_t *i);

char *my_itoa(int nb);
bool is_in_list(char *str, const char **list);
void free_char(char *buffer, char *message, char *temp, char **arg);
bool *get_value(void);

#endif // CLIENT_H
