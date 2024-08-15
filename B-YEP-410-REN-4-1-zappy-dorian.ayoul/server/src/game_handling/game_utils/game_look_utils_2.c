/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

char *game_get_players_on_tile(core_t *core, client_t *client, pos_t *pos,
    char *buff)
{
    node_t *node = NULL;
    trantorian_t *trant = NULL;

    foreach(core->game->trantorians->head, node) {
        trant = (trantorian_t *)node->data;
        if (trant->state != TRANT_LIVING)
            continue;
        if (trant->pos.x != pos->x || trant->pos.y != pos->y)
            continue;
        buff = game_get_look_ressource_str("player", 1, buff);
        if (buff == NULL) {
            game_return_error_malloc(core, client);
            return NULL;
        }
    }
    return buff;
}
