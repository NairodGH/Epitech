/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

static bool spl_scn_pathz(client_t *client, pps_t *x_y, pos_t sx_sy, char *obj)
{
    size_t n = client->player->number;

    if (string_to_number_object(client->map[round_map(client, sx_sy.y - n, 0)]
        [round_map(client, sx_sy.x + n, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y - n, 0);
        *x_y->x = round_map(client, sx_sy.x + n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y + n, 0)]
        [round_map(client, sx_sy.x - n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x - n, 1);
        *x_y->y = round_map(client, sx_sy.y + n, 0);
        return true;
    }
    return false;
}

static bool spl_scn_paths(client_t *client, pps_t *x_y, pos_t sx_sy, char *obj)
{
    size_t n = client->player->number;

    if (string_to_number_object(client->map[round_map(client, sx_sy.y, 0)]
        [round_map(client, sx_sy.x - n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x - n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y + n, 0)]
        [round_map(client, sx_sy.x + n, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y + n, 0);
        *x_y->x = round_map(client, sx_sy.x + n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y - n, 0)]
        [round_map(client, sx_sy.x - n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x - n, 1);
        *x_y->y = round_map(client, sx_sy.y - n, 0);
        return true;
    }
    return spl_scn_pathz(client, x_y, sx_sy, obj);
}

static bool spl_scan_path(client_t *client, pps_t *x_y, pos_t sx_sy, char *obj)
{
    size_t n = client->player->number;

    if (string_to_number_object(client->map[round_map(client, sx_sy.y + n, 0)]
        [round_map(client, sx_sy.x, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y + n, 0);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y, 0)]
        [round_map(client, sx_sy.x + n, 1)], obj) > 0) {
        *x_y->x = round_map(client, sx_sy.x + n, 1);
        return true;
    }
    if (string_to_number_object(client->map[round_map(client, sx_sy.y - n, 0)]
        [round_map(client, sx_sy.x, 1)], obj) > 0) {
        *x_y->y = round_map(client, sx_sy.y - n, 0);
        return true;
    }
    return spl_scn_paths(client, x_y, sx_sy, obj);
}

bool scan_path_finding(client_t *client, size_t *x, size_t *y, char *obj)
{
    size_t s_x = *x;
    size_t s_y = *y;
    pps_t x_y = {(int *)x, (int *)y};
    pos_t sx_sy = {s_x, s_y};
    size_t size = ((client->size_map.x > client->size_map.y)
        ? client->size_map.x : client->size_map.y);

    while (client->player->number < (size / 2)) {
        if (spl_scan_path(client, &x_y, sx_sy, obj))
            break;
        client->player->number++;
    }
    if (client->player->number == (size / 2))
        return false;
    return true;
}

bool path_finding_object(client_t *client, char *object)
{
    size_t x = client->player->pos.x;
    size_t y = client->player->pos.y;
    size_t save = client->player->number;

    if (string_to_number_object(client->map[y][x], object) > 0) {
        if (strcmp(object, "food") == 0)
            return (get_food_in_cell(client, x, y));
        return true;
    }
    client->player->number = 1;
    if (!scan_path_finding(client, &x, &y, object)) {
        client->player->number = save;
        return false;
    }
    client->player->number = save;
    if (!go_to_next_object(client, (int)x, (int)y))
        return false;
    if (strcmp(object, "food") == 0)
        return (get_food_in_cell(client, x, y));
    return true;
}
