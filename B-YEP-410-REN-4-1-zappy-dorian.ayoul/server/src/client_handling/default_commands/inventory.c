/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const char *inv_elems[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
};

static char *get_inv_elem(client_t *client, char *inventory)
{
    size_t array_size = sizeof(inv_elems) / sizeof(inv_elems[0]);
    char *temp = NULL;
    size_t elem = 0;

    for (size_t i = 0; i < array_size; i++) {
        elem = ((size_t *)(client->trantorian->inventory))[i];
        temp = inventory;
        if (asprintf(&inventory, "%s%s %ld%s", temp, inv_elems[i], elem,
                i + 1 < array_size ? ", " : "") == -1) {
            free(temp);
            return NULL;
        }
        free(temp);
    }
    return inventory;
}

void inventory_e(core_t *core, client_t *client, UNUSED char *command)
{
    char *inventory = strdup("[");
    char *temp = NULL;

    if (inventory == NULL) {
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    inventory = get_inv_elem(client, inventory);
    if (inventory == NULL) {
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    temp = inventory;
    if (asprintf(&inventory, "%s]\n", temp) == -1) {
        free(temp);
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    free(temp);
    client_push_command(core->server, client, inventory);
}

void command_inventory(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = inventory_e;
    client->handler->command_it = 1;
}
