/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

bool split_level_6(client_t *client)
{
    if (client->player->inv->phiras < 1) {
        if (!path_finding_object(client, "phiras"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->phiras, 1, "phiras"))
            return false;
    }
    return (check_level_6(client) ?
        ask_player(client, 6, (client->player->level + '0')) : 1);
}

bool level_6(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 2) {
        if (!path_finding_object(client, "deraumere"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->deraumere, 2, "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 3) {
        if (!path_finding_object(client, "sibur"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->sibur, 3, "sibur"))
            return false;
    }
    return split_level_6(client);
}

static bool split_level_7(client_t *client)
{
    if (client->player->inv->mendiane < 2) {
        if (!path_finding_object(client, "mendiane"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->mendiane, 2, "mendiane"))
            return false;
    }
    if (client->player->inv->phiras < 2) {
        if (!path_finding_object(client, "phiras"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->phiras, 2, "phiras"))
            return false;
    }
    if (client->player->inv->thystame < 1) {
        if (!path_finding_object(client, "thystame"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->thystame, 1, "thystame"))
            return false;
    }
    return (check_level_7(client) ?
        ask_player(client, 6, (client->player->level + '0')) : 1);
}

bool level_7(client_t *client)
{
    if (client->player->inv->linemate < 2) {
        if (!path_finding_object(client, "linemate"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->linemate, 2, "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 2) {
        if (!path_finding_object(client, "deraumere"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->deraumere, 2, "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 2) {
        if (!path_finding_object(client, "sibur"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->sibur, 2, "sibur"))
            return false;
    }
    return split_level_7(client);
}
