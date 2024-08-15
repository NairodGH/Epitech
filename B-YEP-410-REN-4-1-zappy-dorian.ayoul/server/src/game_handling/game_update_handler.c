/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void game_update_handler(core_t *core, client_t *client)
{
    if (client->handler->command_it > 0) {
        client->handler->command_it--;
    } else if (client->handler->command != NULL) {
        client->handler->command(core, client, client->handler->params);
        handler_clear(client->handler);
    } else {
        handler_clear(client->handler);
    }
}

void game_update_handlers(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    client_t *client = NULL;

    foreach_safe(core->server->clients->head, node, safe) {
        client = (client_t *)node->data;
        if (client->type == CLI_DEFAULT) {
            game_update_handler(core, client);
        }
    }
}
