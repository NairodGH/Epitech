/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static int get_x_y(char *command, size_t *x, size_t *y)
{
    char *tmp = strtok(command, " \t");

    for (size_t i = 0; i < 2; i++) {
        if (tmp == NULL)
            return ERROR;
        if (i == 0) {
            *x = atol(tmp);
        } else {
            *y = atol(tmp);
        }
        tmp = strtok(NULL, " \t");
    }
    return SUCCESS;
}

char *command_write_tile_content(core_t *core, client_t *client,
    size_t x, size_t y)
{
    char *buffer = NULL;

    if (asprintf(&buffer, "bct %ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
            x, y,
            GET_CELL(core->game->map, x, y)->food,
            GET_CELL(core->game->map, x, y)->linemate,
            GET_CELL(core->game->map, x, y)->deraumere,
            GET_CELL(core->game->map, x, y)->sibur,
            GET_CELL(core->game->map, x, y)->mendiane,
            GET_CELL(core->game->map, x, y)->phiras,
            GET_CELL(core->game->map, x, y)->thystame) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return NULL;
    }
    return buffer;
}

void command_bct(core_t *core, client_t *client, char *command)
{
    size_t x = 0;
    size_t y = 0;
    char *buffer = NULL;

    if (get_x_y(command, &x, &y) == ERROR || x >= core->game->map->width ||
            y >= core->game->map->height) {
        fprintf(stderr, "[ERROR] GUI Bad params\n");
        command_sbp(core, client);
        return;
    }
    buffer = command_write_tile_content(core, client, x, y);
    if (buffer == NULL)
        return;
    client_push_command(core->server, client, buffer);
}
