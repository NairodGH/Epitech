/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client ai
*/

#include "zappy_ai.h"

int string_to_number_object_in_inv(inventory_t inv, char *object_name)
{
    if (strcmp(object_name, "food") == 0)
        return inv.food;
    if (strcmp(object_name, "deraumere") == 0)
        return inv.deraumere;
    if (strcmp(object_name, "linemate") == 0)
        return inv.linemate;
    if (strcmp(object_name, "mendiane") == 0)
        return inv.mendiane;
    if (strcmp(object_name, "phiras") == 0)
        return inv.phiras;
    if (strcmp(object_name, "sibur") == 0)
        return inv.sibur;
    if (strcmp(object_name, "thystame") == 0)
        return inv.thystame;
    return 0;
}

int string_to_number_object(map_t map, char *object_name)
{
    if (strcmp(object_name, "food") == 0)
        return map.inv->food;
    if (strcmp(object_name, "deraumere") == 0)
        return map.inv->deraumere;
    if (strcmp(object_name, "linemate") == 0)
        return map.inv->linemate;
    if (strcmp(object_name, "mendiane") == 0)
        return map.inv->mendiane;
    if (strcmp(object_name, "phiras") == 0)
        return map.inv->phiras;
    if (strcmp(object_name, "sibur") == 0)
        return map.inv->sibur;
    if (strcmp(object_name, "thystame") == 0)
        return map.inv->thystame;
    return 0;
}

void free_map_copy(map_t **map, size_t x, size_t y)
{
    size_t max_x = x;
    size_t max_y = y;

    for (size_t y = 0; y < max_y; y++) {
        for (size_t x = 0; x < max_x; x++)
            free(map[y][x].inv);
        free(map[y]);
    }
    free(map);
}
