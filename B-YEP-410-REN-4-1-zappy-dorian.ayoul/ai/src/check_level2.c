/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

bool check_level_3(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 2, 0, 1, 0, 2, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 2 || inv->sibur < 1 || inv->phiras < 2)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}

bool check_level_4(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 1, 1, 2, 0, 1, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 1 || inv->sibur < 2 || inv->phiras < 1
        || inv->deraumere < 1)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}

bool check_level_5(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 1, 2, 1, 3, 0, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 1 || inv->sibur < 1 || inv->mendiane < 3
        || inv->deraumere < 2)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}

bool check_level_6(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 1, 2, 3, 0, 1, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 1 || inv->deraumere < 2 || inv->sibur < 3
        || inv->phiras < 1)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}

bool check_level_7(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 2, 2, 2, 2, 2, 1};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 2 || inv->deraumere < 2 || inv->sibur < 2
        || inv->mendiane < 2 || inv->phiras < 2 || inv->thystame < 1)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}
