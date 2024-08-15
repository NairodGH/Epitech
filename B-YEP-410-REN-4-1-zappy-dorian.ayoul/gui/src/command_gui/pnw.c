/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static player_t *malloc_inv(player_t *player)
{
    player->inv = calloc(1, sizeof(inventory_t));
    if (!player->inv)
        return NULL;
    return player;
}

static player_t *split_create_play(client_t *cli, player_t *player, char *save)
{
    char *temp = NULL;
    char *team_name = NULL;
    node_t *node;

    save = move_str(save);
    temp = get_one_word(save);
    player->level = atoi(temp);
    free(temp);
    save = move_str(save);
    team_name = get_one_word(save);
    foreach(cli->team->head, node) {
        if (strcmp(node->data, team_name) == 0) {
            player->team_name = node->data;
            break;
        }
    }
    if (!node)
        player->team_name = "null";
    free(team_name);
    return malloc_inv(player);
}

static player_t *create_player(client_t *client, char *str)
{
    char *save = str;
    char *temp = NULL;
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->uuid = get_one_word((char *)((size_t)(++save)));
    save = move_str(save);
    temp = get_one_word(save);
    player->pos.x = atoi(temp);
    free(temp);
    save = move_str(save);
    temp = get_one_word(save);
    player->pos.y = (client->size_map.y - 1) - atoi(temp);
    free(temp);
    save = move_str(save);
    temp = get_one_word(save);
    player->dir = atoi(temp);
    free(temp);
    return (split_create_play(client, player, save));
}

int pnw(client_t *client, char *str)
{
    player_t *player;

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    player = create_player(client, str);
    if (!player) {
        fprintf(stderr, "%s[ERROR]%s can't malloc player", R, W);
        return 1;
    }
    list_push_data(client->player, player);
    list_push_data(client->map[player->pos.y][player->pos.x].player, player);
    return 0;
}
