/*
** EPITECH PROJECT, 2022
** server.h
** File description:
** server
*/

#ifndef SERVER_H
    #define SERVER_H
    #include "logging_server.h"
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <uuid/uuid.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include "nlib.h"

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define MAX_CLIENT 20

typedef struct messages_s {
    struct messages_s *head;
    struct messages_s *next;
    char *sender;
    char *receiver;
    char *message;
    time_t time;
} messages_t;

typedef struct team_s {
    struct team_s *head;
    struct team_s *next;
    char *team_name;
    char *team_id;
    char *description;
    char **member;
} team_t;

typedef struct context_t {
    bool team;
    char *channel_name;
    char *thread;
    char *comment;
} context_t;

typedef struct server_s {
    socket_t *socket;
    fd_set fds;
    fd_set readfds;
    fd_set writefds;
    fd_set temp;
    char *buffer;
    int port;
} server_t;

typedef struct clients_s {
    bool is_login;
    char *user_name;
    int fd;
    char *id;
    messages_t *l_message;
    team_t *all_team;
} clients_t;

typedef struct lcli_s {
    struct lcli_s *head;
    struct lcli_s *next;
    struct lcli_s *prev;
    clients_t *client;
    context_t *context;
} lcli_t;

int users(lcli_t *list, char **arg);
int user(lcli_t *list, char **arg);
int login(lcli_t *list, char **arg);
int logout(lcli_t *list, char **arg);
int my_send(lcli_t *list, char **arg);
int messages(lcli_t *list, char **arg);
int subscribe(lcli_t *list, char **arg);
int subscribed(lcli_t *list, char **arg);
int unsubscribe(lcli_t *list, char **arg);
int use(lcli_t *list, char **arg);
int create(lcli_t *list, char **arg);
int list(lcli_t *list, char **arg);
int info(lcli_t *list, char **arg);
int help(lcli_t *list, char **arg);

typedef struct map_s {
    const char *cmd;
    int (*func_ptr)(lcli_t *list, char **arg);
} map_t;

static const map_t com[] =
{
    {"users\0", &users},
    {"user\0", &user},
    {"help\0", &help},
    {"login\0", &login},
    {"logout\0", &logout},
    {"send\0", &my_send},
    {"messages\0", &messages},
    {"subscribe\0", &subscribe},
    {"subscribed\0", &subscribed},
    {"unsubscribe\0", &unsubscribe},
    {"use\0", &use},
    {"create\0", &create},
    {"list\0", &list},
    {"info\0", &info},
    {NULL, NULL}
};

// Function :
int init_server(int port);

void sig_handler(int signum);
bool *get_value(void);

void start_server(server_t *serv, lcli_t *list, clients_t *list_clients);
void end_server(server_t *serv, lcli_t *list);

clients_t *init_client(void);
bool create_client(int fd, lcli_t *list);
void clear_client(lcli_t *list, server_t *serv);
void manage_client(int fd, lcli_t *list, char *buffer, server_t *serv);
lcli_t *get_client(lcli_t *list, int fd);
void print_client(clients_t *list_clients);
void destroy_client(lcli_t *list, int fd);
void clear_team(team_t *team);

void load_data(clients_t *list_clients);
messages_t *load_message(void);
void save_data(lcli_t *list);

char *list_to_string(messages_t *l_message);
void add_message(messages_t *l_message,
    char *message, char *sender, char *receiver);
messages_t *create_empty_message(void);
void clear_message(messages_t *message);
char *list_to_string_id(messages_t *l_message, char *sender, char *receiver);

char **find_arg(char *buffer);
char *get_command(char *str);
void free_command(char **arg, char *clean_str);
int get_len_arg(char **arg);
char *my_ltoa(size_t nb);

char *get_word_message(char *buff, size_t *i);
void send_message(int fd, char *code);
char *array_to_string(char **list_message);
void print_arg(char **arg);

void print_linked_list(lcli_t *list);
lcli_t *create_list(clients_t *list_client);
int count_nb_clients(lcli_t *list);

char *generate_id(void);
char **get_list_member(char *buff, size_t *i);
int find_name_in_member(char **member, char *name);
team_t *load_team(void);
void add_team(team_t *team, char *name, char *id, char *description);
bool remove_member_team(team_t *team, char *name, char *uuid);
bool add_member_in_team(team_t *team, char *name, char *team_id);

void reset_context(context_t *context);

#endif // SERVER_H
