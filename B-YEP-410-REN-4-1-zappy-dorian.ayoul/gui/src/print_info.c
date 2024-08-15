/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils gui
*/

#include "zappy_gui.h"

void print_team(list_t *team)
{
    node_t *node;

    foreach (team->head, node)
        printf("[%s] ", (char *)node->data);
    printf("\n");
}

void print_inventory_map(client_t *client)
{
    for (int y = 0; y != client->size_map.y; y++) {
        for (int x = 0; x != client->size_map.x; x++) {
            printf("%d %d : ", y, x);
            print_inventory(client->map[y][x].inv);
        }
    }
}

void print_inventory(inventory_t *inv)
{
    printf("food = %ld linemate = %ld deraumere = %ld sibur = %ld mendiane"
        " = %ld phiras = %ld thystame = %ld\n", inv->food, inv->linemate,
        inv->deraumere, inv->sibur, inv->mendiane, inv->phiras, inv->thystame);
}

void print_player(player_t *player)
{
    printf("dir = [%d] level = [%d] pos x = [%d] pos y = [%d] "
        "team_name = [%s] uuid = [%s]\n",
        player->dir, player->level, player->pos.x, player->pos.y,
        player->team_name, player->uuid);
    print_inventory(player->inv);
}
