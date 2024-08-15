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
        if (strcmp(obj, objects[i]) == 0)
            return i;
    }
    return -1;
}

void set_e(core_t *core, client_t *client, char *command)
{
    char *obj = get_obj(command);
    inventory_t *inv = client->trantorian->inventory;
    int obj_idx = 0;

    if (obj == NULL) {
        fprintf(stderr, "[ERROR] Missing argument\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    obj_idx = is_obj(obj);
    if (obj_idx == -1 || ((size_t *)inv)[obj_idx] == 0) {
        fprintf(stderr, "[ERROR] Invalid obj\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    ((size_t *)inv)[obj_idx]--;
    inv = GET_CELL(core->game->map, client->trantorian->pos.x,
        client->trantorian->pos.y);
    ((size_t *)inv)[obj_idx]++;
    client_push_command(core->server, client, strdup("ok\n"));
    command_pdr(core, client->trantorian, obj_idx + 1);
}

void command_set(core_t *core, client_t *client, char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->params = strdup(command);
    client->handler->command = set_e;
    client->handler->command_it = 7;
}
