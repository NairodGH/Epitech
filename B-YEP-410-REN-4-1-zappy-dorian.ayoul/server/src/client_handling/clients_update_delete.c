/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

void clients_update_delete(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    client_t *client = NULL;

    foreach_safe(core->server->clients->head, node, safe) {
        client = (client_t *)node->data;
        if (client->to_delete == true)
            client_disconnect(core, client, node);
    }
}
