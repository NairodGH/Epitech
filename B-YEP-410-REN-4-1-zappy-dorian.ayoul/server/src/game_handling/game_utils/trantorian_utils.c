/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

trantorian_t *trantorian_find_free(list_t *trantorians, team_t *team)
{
    node_t *node = NULL;
    trantorian_t *res = NULL;

    foreach(trantorians->head, node) {
        res = (trantorian_t *)node->data;
        if (res->team == team && res->state == TRANT_READY)
            return res;
    }
    return NULL;
}

int trantorian_replace(core_t *core, team_t *team, trantorian_t *trantorian)
{
    node_t *node = NULL;
    trantorian_t *to_replace = NULL;

    foreach(core->game->trantorians->head, node) {
        to_replace = (trantorian_t *)node->data;
        if (to_replace != trantorian)
            continue;
        trantorian_destroy(to_replace);
        to_replace = trantorian_create(team, core->game->map->width,
            core->game->map->height, true);
        if (to_replace == NULL) {
            fprintf(stderr, "[ERROR] Unable to create trantorian\n");
            return ERROR;
        }
        to_replace->state = TRANT_READY;
        node->data = to_replace;
        return SUCCESS;
    }
    return ERROR;
}

bool game_is_trant_on_tile(list_t *trantorians, map_t *map, size_t tile)
{
    node_t *node = NULL;
    trantorian_t *trant = NULL;

    if (trantorians == NULL)
        return false;
    foreach(trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        if (trant->state == TRANT_LIVING &&
                GET_COORD(map, trant->pos.x, trant->pos.y) == tile)
            return true;
    }
    return false;
}

static void game_check_team(core_t *core, team_t *team)
{
    node_t *node = NULL;
    trantorian_t *trant = NULL;
    size_t lvl_max = 0;

    foreach(core->game->trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        if (trant->state != TRANT_LIVING)
            continue;
        if (trant->team == team && trant->level == TRANT_LVL_MAX)
            lvl_max++;
    }
    if (lvl_max >= TRANT_NEEDED) {
        printf("[INFO] Team %s won the game\n", team->name);
        command_seg(core, team);
    }
}

void game_check_wining_team(core_t *core)
{
    node_t *node = NULL;
    team_t *team = NULL;

    foreach(core->game->teams->head, node) {
        team = (team_t *)node->data;
        game_check_team(core, team);
    }
}
