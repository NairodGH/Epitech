/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

static char *get_pos(client_t *client, pos_t *pos, char *str)
{
    char *save = NULL;

    pos->x = atoi(str);
    save = go_next_space(str);
    if (!save)
        return NULL;
    pos->y = (client->size_map.y - 1) - atoi(save);
    return save;
}

static void set_params(client_t *client, pos_t pos, int res)
{
    if (res == 0) {
        client->map[pos.y][pos.x].incantation = STATE_FAILED;
        client->map[pos.y][pos.x].color = BLACK;
        client->map[pos.y][pos.x].it = 0;
    } else {
        client->map[pos.y][pos.x].incantation = STATE_SUCCESS;
        client->map[pos.y][pos.x].color = RAYWHITE;
        client->map[pos.y][pos.x].it = 0;
    }
    client->map[pos.y][pos.x].frame_x = 5;
    client->map[pos.y][pos.x].frame_y = 4;
}

static int command(client_t *client, char *str)
{
    char *save = NULL;
    pos_t pos = {0};
    int res = 0;

    save = get_pos(client, &pos, str);
    if (save == NULL)
        return 1;
    save = go_next_space(save);
    if (!save)
        return 1;
    res = atoi(save);
    set_params(client, pos, res);
    return 0;
}

int pie(client_t *client, char *str)
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
