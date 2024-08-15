/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

size_t get_player_same_level(client_t *client, int level)
{
    size_t y = client->player->pos.y;
    size_t x = client->player->pos.x;
    size_t nb = 1;
    node_t *node;

    if (level == 0)
        return 1;
    foreach (client->map[y][x].player->head, node)
        nb++;
    return nb;
}

bool ask_player(client_t *client, size_t nb_need, char level)
{
    char *com = NULL;

    if (get_player_same_level(client, (level - '0')) < nb_need) {
        if (client->player->broadcast_direction != -1)
            return true;
        if (asprintf(&com, "Broadcast %s %c\n",
            client->player->team_name, level) == -1)
            return false;
        if (client->pending_commands->lenght < 10
            && !send_message_comm(client, com))
            return false;
        free(com);
    } else if (client->pending_commands->lenght < 10 && send_message(client->
        pending_commands, client->command, client->socket, "Incantation\n")) {
        return true;
    }
    return true;
}

bool level_1(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
        return true;
    }
    return (check_level_1(client) ?
        ask_player(client, 1, (client->player->level + '0')) : 1);
}

bool level_2(client_t *client)
{
    if (client->player->inv->linemate < 1) {
        if (!path_finding_object(client, "linemate"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->linemate, 1, "linemate"))
            return false;
    }
    if (client->player->inv->deraumere < 1) {
        if (!path_finding_object(client, "deraumere"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->deraumere, 1, "deraumere"))
            return false;
    }
    if (client->player->inv->sibur < 1) {
        if (!path_finding_object(client, "sibur"))
            return send_message_comm_false(client, "Forward\n");
        if (!get_object(client, client->player->inv->sibur, 1, "sibur"))
            return false;
    }
    return (check_level_2(client) ?
        ask_player(client, 2, (client->player->level + '0')) : 1);
}
