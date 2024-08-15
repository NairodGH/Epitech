/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const dir_tile_e dir_tile[] = {
    TILE_ONE,
    TILE_SEVEN,
    TILE_FIVE,
    TILE_THREE,
};

static char *get_str_ejection(direction_e cli_dir, direction_e pushed_dir)
{
    char *buff = NULL;
    direction_e from = (cli_dir + DIR_SIZE / 2) % DIR_SIZE;
    dir_tile_e tile = dir_tile[(from + (int)pushed_dir) % DIR_SIZE];

    if (asprintf(&buff, "eject: %d\n", (int)tile) == -1) {
        fprintf(stderr, "[ERROR] Could not allocate memory\n");
        return NULL;
    }
    return buff;
}

static bool eject_trantorian(core_t *core, client_t *client, client_t *tmp)
{
    char *buff = NULL;

    game_incr_trant_pos(core->game->map, tmp->trantorian,
        client->trantorian->direction);
    command_pex(core, client->trantorian);
    buff = get_str_ejection(client->trantorian->direction,
        tmp->trantorian->direction);
    if (buff == NULL)
        return false;
    client_push_command(core->server, tmp, buff);
    return true;
}

static bool find_trantorians(core_t *core, client_t *client)
{
    node_t *node = NULL;
    client_t *tmp = NULL;
    bool found = false;

    foreach(core->server->clients->head, node) {
        tmp = (client_t *)node->data;
        if (tmp->trantorian->state != TRANT_LIVING ||
                tmp->trantorian == client->trantorian ||
                tmp->trantorian->pos.x != client->trantorian->pos.x ||
                tmp->trantorian->pos.y != client->trantorian->pos.y)
            continue;
        found = true;
        if (!eject_trantorian(core, client, tmp))
            return false;
    }
    return found;
}

void eject_e(core_t *core, client_t *client, UNUSED char *command)
{
    if (find_trantorians(core, client) == false)
        return client_push_command(core->server, client, strdup("ko\n"));
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_eject(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = eject_e;
    client->handler->command_it = 7;
}
