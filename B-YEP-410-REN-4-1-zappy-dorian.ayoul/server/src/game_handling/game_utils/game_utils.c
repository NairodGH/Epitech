/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void game_remove_trantorian(core_t *core, trantorian_t *trantorian)
{
    list_destroy_data_node(core->server->clients, trantorian->client,
        (void (*)(void *))client_destroy);
    list_destroy_data_node(core->game->trantorians, trantorian,
        (void (*)(void *))trantorian_destroy);
}

team_t *team_get_obj(list_t *teams, const char *to_comp)
{
    node_t *node = NULL;
    team_t *team = NULL;

    foreach(teams->head, node) {
        team = (team_t *)node->data;
        if (strcmp(team->name, to_comp) == 0)
            return team;
    }
    return NULL;
}

void game_return_error_malloc(core_t *core, client_t *client)
{
    fprintf(stderr, "[ERROR] Malloc failed\n");
    client_push_command(core->server, client, strdup("ko\n"));
}

trantorian_t *game_get_trantorian(core_t *core, char *uuid)
{
    node_t *node = NULL;

    foreach(core->game->trantorians->head, node) {
        if (strcmp(((trantorian_t *)node->data)->uuid, uuid) == 0)
            return (trantorian_t *)node->data;
    }
    return NULL;
}
