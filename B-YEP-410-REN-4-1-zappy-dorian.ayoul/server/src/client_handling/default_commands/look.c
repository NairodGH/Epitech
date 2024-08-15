/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const char *ressources_tab[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
};

static const dir_to_coef_t dir_to_coef[] = {
    {DIR_UP, 1, 1, false},
    {DIR_RIGHT, -1, 1, true},
    {DIR_DOWN, -1, -1, false},
    {DIR_LEFT, 1, -1, true},
};

static void set_coord(client_t *client, map_t *map, pos_t **to_look,
    int idx_coef)
{
    ssize_t x = 0;
    ssize_t y = 0;
    size_t act_tile = 0;

    for (size_t i = 0; i < client->trantorian->level + 1; i++) {
        for (size_t j = 0; j < ((2 * i) + 1); j++, act_tile++) {
            x = dir_to_coef[idx_coef].invert == true ?
                (POS_X(client) + i * (dir_to_coef[idx_coef].coef_2)) :
                ((POS_X(client)) + j * (dir_to_coef[idx_coef].coef_1) - i *
                    (dir_to_coef[idx_coef].coef_1));
            y = dir_to_coef[idx_coef].invert == true ?
                ((POS_Y(client)) + j * (dir_to_coef[idx_coef].coef_1) - i *
                    (dir_to_coef[idx_coef].coef_1)) :
                (POS_Y(client) + i * (dir_to_coef[idx_coef].coef_2));
            to_look[act_tile]->x = game_look_filter_coord(x, map->width);
            to_look[act_tile]->y = game_look_filter_coord(y, map->height);
        }
    }
}

static char *game_look_browse_inventory(core_t *core, client_t *client,
    pos_t *pos, char *buff)
{
    inventory_t *inv = GET_CELL(core->game->map, pos->x, pos->y);

    for (size_t j = 0; j < RESSOURCES_NBR; j++) {
        buff = game_get_look_ressource_str(ressources_tab[j],
            ((size_t *)inv)[j], buff);
        if (buff == NULL) {
            fprintf(stderr, "[ERROR] Malloc failed\n");
            client_push_command(core->server, client, strdup("ko\n"));
            return (NULL);
        }
    }
    return buff;
}

static void game_print_look_ret(core_t *core, client_t *client,
    pos_t **to_look, size_t nbr)
{
    char *buff = strdup("[");
    char *temp = NULL;

    if (buff == NULL)
        return game_return_error_malloc(core, client);
    for (size_t i = 0; i < nbr; i++) {
        buff = game_get_players_on_tile(core, client,
            to_look[i], buff);
        if (buff == NULL)
            return;
        buff = game_look_browse_inventory(core, client,
            to_look[i], buff);
        if (buff == NULL)
            return;
        temp = buff;
        if (asprintf(&buff, "%s%s", buff, (i == nbr - 1) ? "]\n" : ", ") == -1)
            return game_return_error_malloc(core, client);
        free(temp);
    }
    client_push_command(core->server, client, buff);
}

void look_e(core_t *core, client_t *client, UNUSED char *command)
{
    size_t tile_nbr = game_get_tile_nbr(client->trantorian->level + 1);
    pos_t **to_look = game_init_pos_to_look(tile_nbr);

    if (to_look == NULL) {
        fprintf(stderr, "[ERROR] Can't malloc\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    set_coord(client, core->game->map, to_look,
        (int)client->trantorian->direction);
    game_print_look_ret(core, client, to_look, tile_nbr);
    game_destroy_pos_to_look(to_look);
}

void command_look(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    client->handler->command = look_e;
    client->handler->command_it = 7;
}
