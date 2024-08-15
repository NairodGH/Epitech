/*
** EPITECH PROJECT, 2022
** inventory.c
** File description:
** inventory ai
*/

#include "zappy_ai.h"

char *go_to_next_num(char *str)
{
    size_t i = 0;

    if (!str)
        return "";
    for (i = 0; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i++);
    if (str[i] == '\0')
        return "";
    return &str[i];
}

void fill_inventory_player(player_t *player, char *content)
{
    for (char *stone; (stone = get_cell(content)); free(stone)) {
        if (strstr(stone, "food") != NULL)
            player->inv->food = atoi(go_to_next_num(stone));
        if (strstr(stone, "deraumere") != NULL)
            player->inv->deraumere = atoi(go_to_next_num(stone));
        if (strstr(stone, "linemate") != NULL)
            player->inv->linemate = atoi(go_to_next_num(stone));
        if (strstr(stone, "mendiane") != NULL)
            player->inv->mendiane = atoi(go_to_next_num(stone));
        if (strstr(stone, "phiras") != NULL)
            player->inv->phiras = atoi(go_to_next_num(stone));
        if (strstr(stone, "sibur") != NULL)
            player->inv->sibur = atoi(go_to_next_num(stone));
        if (strstr(stone, "thystame") != NULL)
            player->inv->thystame = atoi(go_to_next_num(stone));
        if ((content = go_next_chr(content, ',')))
            (char *)((size_t)content++);
    }
}

int inventory(client_t *client, char *str)
{
    char *save = str;

    if (!client->player->inv)
        client->player->inv = malloc(sizeof(inventory_t));
    if (!client->player->inv) {
        fprintf(stderr, "%s[ERROR]%s Can't malloc player inv", R, W);
        return 1;
    }
    fill_inventory_player(client->player, save);
    return 0;
}
