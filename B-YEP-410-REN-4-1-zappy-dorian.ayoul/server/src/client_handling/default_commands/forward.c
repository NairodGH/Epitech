/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static size_t control_dir(size_t last_pos, size_t max_pos, bool incr)
{
    if (incr)
        return (last_pos + 1) % max_pos;
    return (last_pos + max_pos - 1) % max_pos;
}

void game_incr_trant_pos(map_t *map, trantorian_t *trant,
    direction_e direction)
{
    switch (direction) {
        case DIR_UP:
            trant->pos.y = control_dir(trant->pos.y,
                map->height, true);
            break;
        case DIR_RIGHT:
            trant->pos.x = control_dir(trant->pos.x,
                map->width, true);
            break;
        case DIR_DOWN:
            trant->pos.y = control_dir(trant->pos.y,
                map->height, false);
            break;
        case DIR_LEFT:
            trant->pos.x = control_dir(trant->pos.x,
                map->width, false);
            break;
        default:
            return;
    }
}

void forward_e(core_t *core, client_t *client, UNUSED char *command)
{
    game_incr_trant_pos(core->game->map, client->trantorian,
        client->trantorian->direction);
    client_push_command(core->server, client, strdup("ok\n"));
}

void command_forward(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = forward_e;
    client->handler->command_it = 7;
}
