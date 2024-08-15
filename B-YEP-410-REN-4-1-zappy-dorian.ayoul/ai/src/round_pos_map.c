/*
** EPITECH PROJECT, 2022
** send_message.c
** File description:
** send_message ai
*/

#include "zappy_ai.h"

int round_map(client_t *client, int pos, bool is_x)
{
    if (is_x) {
        if (pos >= client->size_map.x)
            return pos - client->size_map.x;
        if (pos < 0)
            return pos + client->size_map.x;
        return pos;
    } else {
        if (pos >= client->size_map.y)
            return pos - client->size_map.y;
        if (pos < 0)
            return pos + client->size_map.y;
    }
    return pos;
}

static void split_find_closest_round(client_t *client, int *dest_x, int *dest_y)
{
    int src_x = (int)client->player->pos.x;
    int src_y = (int)client->player->pos.y;

    if (*dest_x < src_x && *dest_x > 0) {
        if (client->player->dir == West
            && src_x - *dest_x > ((*dest_x + client->size_map.x) - src_x) + 2)
            *dest_x = client->size_map.x + *dest_x;
        if (client->player->dir != West
            && src_x - *dest_x > ((*dest_x + client->size_map.x) - src_x))
            *dest_x = client->size_map.x + *dest_x;
    }
    if (*dest_y < src_y && *dest_y > 0) {
        if (client->player->dir == North
            && src_y - *dest_y > ((*dest_y + client->size_map.y) - src_y) + 2)
            *dest_y = client->size_map.y + *dest_y;
        if (client->player->dir != North
            && src_y - *dest_y > ((*dest_y + client->size_map.y) - src_y))
            *dest_y = client->size_map.y + *dest_y;
    }
}

void find_closest_round(client_t *client, int *dest_x, int *dest_y)
{
    int src_x = (int)client->player->pos.x;
    int src_y = (int)client->player->pos.y;

    if (*dest_x > src_x) {
        if (client->player->dir == East
            && *dest_x - src_x > ((client->size_map.x - *dest_x) + src_x) + 2)
            *dest_x = *dest_x - client->size_map.x;
        if (client->player->dir != East
            && *dest_x - src_x > ((client->size_map.x - *dest_x) + src_x))
            *dest_x = *dest_x - client->size_map.x;
    }
    if (*dest_y > src_y) {
        if (client->player->dir == South
            && *dest_y - src_y > ((client->size_map.y - *dest_y) + src_y) + 2)
            *dest_y = *dest_y - client->size_map.y;
        if (client->player->dir != South
            && *dest_y - src_y > ((client->size_map.y - *dest_y) + src_y))
            *dest_y = *dest_y - client->size_map.y;
    }
    split_find_closest_round(client, dest_x, dest_y);
}

bool get_size_map(client_t *client, char *str)
{
    client->size_map.x = atoi(str);
    client->size_map.y = atoi(strchr(str, ' '));
    if (client->size_map.x <= 0 || client->size_map.y <= 0) {
        fprintf(stderr, "%s[ERROR]%s bad size map", R, W);
        return false;
    }
    if (!create_map(client)) {
        fprintf(stderr, "%s[ERROR]%s can't malloc map\n", R, W);
        return false;
    }
    if (client->client_connected) {
        client->init = false;
        if (!basic_command(client))
            return false;
    }
    return true;
}
