/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static const inventory_t stones_needed[] = {
    {0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0},
    {0, 2, 0, 1, 0, 2, 0},
    {0, 1, 1, 2, 0, 1, 0},
    {0, 1, 2, 1, 3, 0, 0},
    {0, 1, 2, 3, 0, 1, 0},
    {0, 2, 2, 2, 2, 2, 1},
};

static const size_t player_needed[] = {
    1, 2, 2, 4, 4, 6, 6
};

bool incantation_check_tile(map_t *map, pos_t *pos, size_t level)
{
    inventory_t *inventory = GET_CELL(map, pos->x, pos->y);

    for (size_t i = 1; i < RESSOURCES_NBR; i++) {
        if (((size_t *)inventory)[i] !=
            ((size_t *)(&stones_needed[level - IDX]))[i])
            return false;
    }
    return true;
}

static incantation_t *get_incantation(core_t *core, trantorian_t *trant)
{
    node_t *node = NULL;
    trantorian_t *temp = NULL;
    incantation_t *incantation = incantation_create(trant->level, trant->pos);

    if (incantation == NULL)
        return NULL;
    foreach(core->game->trantorians->head, node) {
        temp = (trantorian_t *)node->data;
        if (temp == trant)
            continue;
        if (temp->pos.x != trant->pos.x || temp->pos.y != trant->pos.y)
            continue;
        if (temp->level != trant->level)
            continue;
        if (temp->state != TRANT_LIVING)
            continue;
        list_push_data(incantation->trantorians, temp);
    }
    list_push_data(incantation->trantorians, trant);
    return incantation;
}

static incantation_t *can_incant(core_t *core, trantorian_t *trant)
{
    incantation_t *incantation = NULL;

    if (incantation_check_tile(core->game->map, &trant->pos, trant->level)
            == false)
        return NULL;
    incantation = get_incantation(core, trant);
    if (incantation == NULL)
        return NULL;
    if (incantation->trantorians->lenght < player_needed[trant->level - IDX]) {
        incantation_destroy(incantation);
        return NULL;
    }
    incantation->it_rem = 300;
    incantation->needed = &stones_needed[trant->level - IDX];
    list_push_data(core->game->incantations, incantation);
    return incantation;
}

void incantation_e(core_t *core, client_t *client, UNUSED char *command)
{
    incantation_t *incantation = NULL;
    node_t *node = NULL;
    trantorian_t *trant = NULL;

    incantation = can_incant(core, client->trantorian);
    if (incantation == NULL) {
        fprintf(stderr, "[ERROR] Incantation failed\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    foreach(incantation->trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        client_push_command(core->server, trant->client,
            strdup("Elevation underway\n"));
    }
    command_pic(core, client->trantorian, incantation->trantorians);
}

void command_incantation(core_t *core, client_t *client, UNUSED char *command)
{
    if (client == NULL || client->trantorian == NULL) {
        fprintf(stderr, "[ERROR] Invalid client\n");
        client_push_command(core->server, client, strdup("ko\n"));
        return;
    }
    incantation_e(core, client, NULL);
    client->handler->command_it = 300;
}
