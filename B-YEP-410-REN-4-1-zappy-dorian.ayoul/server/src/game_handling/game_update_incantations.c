/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static const size_t player_needed[] = {
    1, 2, 2, 4, 4, 6, 6
};

static char *get_level_str(size_t new_lvl)
{
    char *buff = NULL;

    if (asprintf(&buff, "Current level: %ld\n", new_lvl) == -1)
        return NULL;
    return buff;
}

static bool check_remove_bad_pos(incantation_t *incantation)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    trantorian_t *temp = NULL;
    size_t available = 0;

    foreach_safe(incantation->trantorians->head, node, safe) {
        temp = (trantorian_t *)node->data;
        if (temp->pos.x == incantation->pos.x &&
                temp->pos.y == incantation->pos.y) {
            available++;
            temp->lvl_up = true;
        } else {
            temp->lvl_up = false;
        }
    }
    if (available < player_needed[incantation->level - IDX])
        return false;
    return true;
}

static void game_increase_trantorians_level(core_t *core,
    incantation_t *incantation)
{
    node_t *node = NULL;
    trantorian_t *trant = NULL;
    bool lvl_up = false;
    char *temp = NULL;

    foreach(incantation->trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        if (trant->lvl_up == true) {
            lvl_up = true;
            trant->level++;
        }
        temp = get_level_str(trant->level);
        if (temp == NULL) {
            fprintf(stderr, "[ERROR] Malloc failed\n");
            continue;
        }
        client_push_command(core->server, trant->client, temp);
    }
    command_pie(core, incantation->trantorians->head->data, lvl_up);
}

static bool game_update_invocation(core_t *core, incantation_t *incantation)
{
    inventory_t *invent = NULL;

    if (incantation->it_rem > 0) {
        incantation->it_rem--;
        return false;
    }
    if (incantation_check_tile(core->game->map,
            &incantation->pos, incantation->level) == false ||
            check_remove_bad_pos(incantation) == false)
        return false;
    game_increase_trantorians_level(core, incantation);
    invent = GET_CELL(core->game->map, incantation->pos.x, incantation->pos.y);
    invent->linemate -= incantation->needed->linemate;
    invent->deraumere -= incantation->needed->deraumere;
    invent->sibur -= incantation->needed->sibur;
    invent->mendiane -= incantation->needed->mendiane;
    invent->phiras -= incantation->needed->phiras;
    invent->thystame -= incantation->needed->thystame;
    return true;
}

void game_update_incantations(core_t *core)
{
    node_t *node = NULL;
    node_t *safe = NULL;
    incantation_t *incantation = NULL;

    foreach_safe(core->game->incantations->head, node, safe) {
        incantation = (incantation_t *)node->data;
        if (game_update_invocation(core, incantation) == true) {
            list_remove_node(core->game->incantations, node);
            list_destroy_node(node, (void (*)(void *))incantation_destroy);
        }
    }
}
