/*
** EPITECH PROJECT, 2022
** movement.c
** File description:
** movement ai
*/

#include "zappy_ai.h"

static void change_dir(client_t *client)
{
    if (client->player->dir == South) {
        client->player->pos.y += 1;
        if (client->player->pos.y >= client->size_map.y)
            client->player->pos.y = 0;
    }
    if (client->player->dir == North) {
        client->player->pos.y -= 1;
        if (client->player->pos.y < 0)
            client->player->pos.y = client->size_map.y - 1;
    }
    if (client->player->dir == East) {
        client->player->pos.x += 1;
        if (client->player->pos.x >= client->size_map.x)
            client->player->pos.x = 0;
    }
    if (client->player->dir == West) {
        client->player->pos.x -= 1;
        if (client->player->pos.x < 0)
            client->player->pos.x = client->size_map.x - 1;
    }
}

static void find_right_dir(client_t *client, bool right)
{
    if (client->player->dir == North) {
        client->player->dir = (right ? East : West);
        return;
    }
    if (client->player->dir == South) {
        client->player->dir = (right ? West : East);
        return;
    }
    if (client->player->dir == East) {
        client->player->dir = (right ? South : North);
        return;
    }
    if (client->player->dir == West) {
        client->player->dir = (right ? North : South);
        return;
    }
}

int forward_movement(client_t *client, char *str)
{
    if (strcmp(str, "ok") == 0) {
        change_dir(client);
        printf("%s[COMMAND]%s Forward\n", B, W);
        printf("%s[INFO]%s command_pending left %ld\n",
            G, W, client->pending_commands->lenght);
        return 0;
    }
    return 1;
}

int right_movement(client_t *client, char *str)
{
    if (strcmp(str, "ok") == 0) {
        find_right_dir(client, true);
        printf("%s[COMMAND]%s Right\n", B, W);
        printf("%s[INFO]%s command_pending left %ld\n",
            G, W, client->pending_commands->lenght);
        return 0;
    }
    return 1;
}

int left_movement(client_t *client, char *str)
{
    if (strcmp(str, "ok") == 0) {
        find_right_dir(client, false);
        printf("%s[COMMAND]%s Left\n", B, W);
        printf("%s[INFO]%s command_pending left %ld\n",
            G, W, client->pending_commands->lenght);
        return 0;
    }
    return 1;
}
