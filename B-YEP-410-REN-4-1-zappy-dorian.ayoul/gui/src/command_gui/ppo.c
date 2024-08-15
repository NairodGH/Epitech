/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static void change_player_pos_in_map(client_t *client, node_t *node, pos_t pos)
{
    node_t *temp = NULL;
    node_t *save = NULL;
    pos_t new_pos = {((player_t *)node->data)->pos.x,
        ((player_t *)node->data)->pos.y};

    foreach_safe (client->map[pos.y][pos.x].player->head, temp, save) {
        if (strcmp(((player_t *)node->data)->uuid,
            ((player_t *)temp->data)->uuid) == 0) {
            list_remove_node(client->map[pos.y][pos.x].player, temp);
            break;
        }
    }
    list_push_data(client->map[new_pos.y][new_pos.x].player, node->data);
}

static bool split_ppo(client_t *client, node_t *node, char *save, pos_t pos)
{
    char *temp = NULL;

    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->pos.x = atoi(temp);
    free(temp);
    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->pos.y = (client->size_map.y - 1) - atoi(temp);
    free(temp);
    ((pos.x != ((player_t *)node->data)->pos.x || pos.y != ((player_t *)node->
        data)->pos.y) ? change_player_pos_in_map(client, node, pos) : 0);
    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->dir = atoi(temp);
    free(temp);
    return true;
}

int ppo(client_t *client, char *str)
{
    node_t *node = NULL;
    char *uuid = NULL;
    char *save = strdup(str);
    char *copy = save;

    if (strcmp(str, "suc\n") == 0 || strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc/sbp command received", R, W);
        return 1;
    }
    uuid = get_one_word(save);
    foreach (client->player->head, node)
        if (strcmp(((player_t *)node->data)->uuid, uuid) == 0)
            break;
    if (!split_ppo(client, node, save, ((player_t *)node->data)->pos))
        fprintf(stderr, "%s[ERROR]%s can't malloc ppo", R, W);
    free(copy);
    free(uuid);
    return 0;
}

static bool split_plv(node_t *node, char *save, char *uuid)
{
    char *temp = NULL;

    save = move_str(save);
    if (!(temp = get_one_word(save)))
        return false;
    ((player_t *)node->data)->level = atoi(temp);
    free(temp);
    free(uuid);
    return true;
}

int plv(client_t *client, char *str)
{
    node_t *node = NULL;
    char *uuid = NULL;
    char *save = strdup(str);
    char *copy = save;

    if (strcmp(str, "suc\n") == 0 || strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc/sbp command received", R, W);
        return 1;
    }
    uuid = get_one_word(save);
    foreach(client->player->head, node) {
        if (strcmp(((player_t *)node->data)->uuid, uuid) == 0)
            break;
    }
    if (!split_plv(node, save, uuid))
        fprintf(stderr, "%s[ERROR]%s can't malloc plv", R, W);
    free(copy);
    return 0;
}
