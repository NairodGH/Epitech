/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef CLIENT_H
    #define CLIENT_H

    #define POS_X(client) (client->trantorian->pos.x)
    #define POS_Y(client) (client->trantorian->pos.y)

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

    #include "nlib.h"

    #include "trantorian.h"

typedef enum {
    CLI_UNKNOWN,

    CLI_DEFAULT,
    CLI_GUI,
} client_type_e;

struct command_handler_s;
struct trantorian_s;

typedef struct client_s {
    socket_t *sock;
    struct command_handler_s *handler;
    list_t *command_list;
    client_type_e type;
    struct trantorian_s *trantorian;
    bool to_delete;
} client_t;

void client_destroy_command(char *command);
client_t *client_create(int fd);
void client_destroy(client_t *client);

#endif // CLIENT_H
