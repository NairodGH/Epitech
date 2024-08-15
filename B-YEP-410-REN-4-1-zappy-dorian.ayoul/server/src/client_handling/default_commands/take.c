/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const char *objects[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
};

static char *get_obj(char *command)
{
    for (size_t i = 0; i < strlen(command); i++) {
        if (command[i] != ' ') {
            return &command[i];
        }
    }
    return NULL;
}

static int is_obj(char *obj)
{
    for (int i = 0; i < RESSOURCES_NBR; i++) {
        if (strncmp(obj, objects[i], strlen(objects[i])) == 0)
            return i;
    }
    return -1;
}

static void print_err(core_t *core, client_t *client)
{
    fprintf(stderr, "[ERROR] Invalid param\n");
    client_push_command(core->server, client, strdup("ko\n"));
}

void take_e(core_t *core, client_t *client, char *command)
{
    char *obj = get_obj(command);
    inventory_t *inv = NULL;
    int obj_idx = 0;

    if (obj == NULL)
        return print_err(core, client);
    obj_idx = is_obj(obj);
    if (obj_idx == -1)
        return print_err(core, client);
    inv = GET_CELL(core->game->map, client->trantorian->pos.x,
        client->trantorian->pos.y);
    if (((size_t *)inv)[obj_idx] == 0)
        return print_err(core, client);
    ((size_t *)inv)[obj_idx]--;
    inv = client->trantorian->inventory;
    ((size_t *)inv)[obj_idx]++;
    client_push_command(core->server, client, strdup("ok\n"));
    command_pdr(core, client->trantorian, obj_idx + 1);
}

void command_take(core_t *core, client_t *client, char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->params = strdup(command);
    client->handler->command = take_e;
    client->handler->command_it = 7;
}
