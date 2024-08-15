/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *get_msg(char *command)
{
    for (size_t i = 0; i < strlen(command); i++) {
        if (command[i] != ' ') {
            return &command[i];
        }
    }
    return NULL;
}

static void send_msg(core_t *core, client_t *client, client_t *to_send,
    char *msg)
{
    dir_tile_e dir_tile = game_calc_direction(core->game->map,
        to_send->trantorian->direction, &client->trantorian->pos,
        &to_send->trantorian->pos);
    char *broad = NULL;

    if (dir_tile == TILE_NONE) {
        fprintf(stderr, "[ERROR] Client %s tried to send a message to %s\n",
            client->trantorian->uuid, to_send->trantorian->uuid);
        return;
    }
    if (asprintf(&broad, "message %d, %s\n", dir_tile, msg) == -1) {
        fprintf(stderr, "[ERROR] Failed to malloc text\n");
        return;
    }
    client_push_command(core->server, to_send, broad);
}

void broadcast_e(core_t *core, client_t *client, char *command)
{
    char *msg = get_msg(command);
    node_t *node = NULL;
    client_t *temp = NULL;

    if (msg == NULL) {
        fprintf(stderr, "[ERROR] Invalid broadcast text\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->type = CLI_UNKNOWN;
    foreach(core->server->clients->head, node) {
        temp = (client_t *)node->data;
        if (temp->type == CLI_DEFAULT)
            send_msg(core, client, temp, command);
    }
    client->type = CLI_DEFAULT;
    client_push_command(core->server, client, strdup("ok\n"));
    command_pbc(core, client->trantorian, command);
}

void command_broadcast(core_t *core, client_t *client, char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->params = strdup(command);
    client->handler->command = broadcast_e;
    client->handler->command_it = 7;
}
