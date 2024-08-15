/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static char *split_fill_inv(client_t *client, char *save, size_t x, size_t y)
{
    client->map[y][x].inv->deraumere = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->sibur = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->mendiane = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->phiras = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->thystame = atoi(save);
    save = go_next_space(save);
    return (save);
}

static char *fill_inventory(client_t *client, char *str)
{
    size_t x = atoi(str);
    size_t y = 0;
    char *save = go_next_space(str);

    if (!save)
        return NULL;
    y = (client->size_map.y - 1) - atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->food = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    client->map[y][x].inv->linemate = atoi(save);
    save = go_next_space(save);
    if (!save)
        return NULL;
    return (split_fill_inv(client, save, x, y));
}

int bct(client_t *client, char *str)
{
    char *save = str;

    if (!save)
        return 1;
    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    do {
        save = fill_inventory(client, save);
    } while (save);
    return 0;
}
