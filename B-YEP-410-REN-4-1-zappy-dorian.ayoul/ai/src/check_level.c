/*
** EPITECH PROJECT, 2022
** stdin.c
** File description:
** stdin ai
*/

#include "zappy_ai.h"

bool change_stone_in_cell(
    client_t *client, char *take_set, char *object, inventory_t inv)
{
    char *command = NULL;
    int cell_object = string_to_number_object_in_inv(*(client->map
        [client->player->pos.y][client->player->pos.x].inv), object);
    int inv_object = string_to_number_object_in_inv(inv, object);

    if (asprintf(&command, "%s %s\n", take_set, object) == -1) {
        fprintf(stderr, "%s[ERROR]%s Malloc error asprintf\n", R, W);
            return false;
    }
    while (cell_object != inv_object && client->pending_commands->lenght < 10) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, command)) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        (strcmp(take_set, "Take") == 0 ? cell_object-- : cell_object++);
    }
    free(command);
    return (cell_object != inv_object ? false : true);
}

bool drop_stone_needed(client_t *client, inventory_t inv, inventory_t cell_inv)
{
    if (cell_inv.linemate < inv.linemate
        && !change_stone_in_cell(client, "Set", "linemate", inv))
        return false;
    if (cell_inv.deraumere < inv.deraumere
        && !change_stone_in_cell(client, "Set", "deraumere", inv))
        return false;
    if (cell_inv.sibur < inv.sibur
        && !change_stone_in_cell(client, "Set", "sibur", inv))
        return false;
    if (cell_inv.mendiane < inv.mendiane
        && !change_stone_in_cell(client, "Set", "mendiane", inv))
        return false;
    if (cell_inv.phiras < inv.phiras
        && !change_stone_in_cell(client, "Set", "phiras", inv))
        return false;
    if (cell_inv.thystame < inv.thystame
        && !change_stone_in_cell(client, "Set", "thystame", inv))
        return false;
    return true;
}

int take_everything(client_t *client, inventory_t inv, inventory_t cell_inv)
{
    if (!send_message_comm(client, "Inventory\n")
        || (cell_inv.linemate > inv.linemate
        && !change_stone_in_cell(client, "Take", "linemate", inv)))
        return false;
    if (cell_inv.deraumere > inv.deraumere
        && !change_stone_in_cell(client, "Take", "deraumere", inv))
        return false;
    if (cell_inv.sibur > inv.sibur
        && !change_stone_in_cell(client, "Take", "sibur", inv))
        return false;
    if (cell_inv.mendiane > inv.mendiane
        && !change_stone_in_cell(client, "Take", "mendiane", inv))
        return false;
    if (cell_inv.phiras > inv.phiras
        && !change_stone_in_cell(client, "Take", "phiras", inv))
        return false;
    if (cell_inv.thystame > inv.thystame
        && !change_stone_in_cell(client, "Take", "thystame", inv))
        return false;
    return true;
}

bool check_level_1(client_t *client)
{
    inventory_t inventory = {0, 1, 0, 0, 0, 0, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (client->player->inv->linemate < 1)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}

bool check_level_2(client_t *client)
{
    inventory_t *inv = client->player->inv;
    inventory_t inventory = {0, 1, 1, 1, 0, 0, 0};
    inventory_t *cell_inv =
        client->map[client->player->pos.y][client->player->pos.x].inv;

    if (inv->linemate < 1 || inv->deraumere < 1 || inv->sibur < 1)
        return false;
    if (!take_everything(client, inventory, *cell_inv))
        return false;
    return (drop_stone_needed(client, inventory, *cell_inv));
}
