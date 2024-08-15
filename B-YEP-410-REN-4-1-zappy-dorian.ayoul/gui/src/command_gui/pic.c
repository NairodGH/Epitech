/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static int get_pos(client_t *client, pos_t *pos, char *str)
{
    char *save = NULL;

    pos->x = atoi(str);
    save = go_next_space(str);
    if (!save)
        return 1;
    pos->y = (client->size_map.y - 1) - atoi(save);
    return 0;
}

static int command(client_t *client, char *str)
{
    pos_t pos = {0};

    if (get_pos(client, &pos, str) != 0)
        return 1;
    client->map[pos.y][pos.x].incantation = STATE_INCANT;
    client->map[pos.y][pos.x].it = 300;
    return 0;
}

int pic(client_t *client, char *str)
{
    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    return command(client, str);
}
