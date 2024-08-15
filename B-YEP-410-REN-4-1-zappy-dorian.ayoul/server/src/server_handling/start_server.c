/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static int trantorian_insert_in_team(core_t *core, team_t *team)
{
    trantorian_t *trantorian = NULL;

    for (size_t i = 0; i < core->game->cli_per_team; i++) {
        trantorian = trantorian_create(team, core->game->map->width,
            core->game->map->height, true);
        if (trantorian == NULL) {
            fprintf(stderr, "[ERROR] Unable to create trantorian\n");
            return ERROR;
        }
        trantorian->state = TRANT_READY;
        if (list_push_data(core->game->trantorians,
            trantorian) == LIST_FAILURE) {
            fprintf(stderr, "[ERROR] Unable to insert trantorian in list\n");
            trantorian_destroy(trantorian);
            return ERROR;
        }
    }
    return SUCCESS;
}

int trantorian_init(core_t *core)
{
    node_t *node = NULL;

    foreach(core->game->teams->head, node) {
        if (trantorian_insert_in_team(core, (team_t *)node->data) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int core_init(core_t *core, args_t *args)
{
    core->game = game_create(args->teams, args->width, args->height,
        args->cli_per_team);
    if (core->game == NULL) {
        return ERROR;
    }
    core->game->freq = args->freq;
    core->server = server_create(args->port);
    if (core->server == NULL) {
        return ERROR;
    }
    return SUCCESS;
}

int server_start(args_t *args)
{
    core_t *core = core_create();

    if (core == NULL)
        return ERROR;
    if (core_init(core, args) == ERROR || trantorian_init(core) == ERROR) {
        core_destroy(core);
        return ERROR;
    }
    printf("[INFO] Server listening on port %d\n", core->server->port);
    return server_loop(core);
}
