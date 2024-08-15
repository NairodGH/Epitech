/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool get_food_basic(client_t *client)
{
    if (!path_finding_object(client, "food") && !send_message(client->
        pending_commands, client->command, client->socket, "Forward\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}

static bool go_to_broadcast_dir3(client_t *client, size_t d)
{
    if (d == 3) {
        if (!send_message_comm(client, "Left\n"))
            return false;
        return (send_message_comm(client, "Forward\n"));
    } else {
        if (!send_message_comm(client, "Right\n"))
            return false;
        return (send_message_comm(client, "Forward\n"));
    }
    return true;
}

static bool go_to_broadcast_dir2(client_t *client, size_t d)
{
    if (d == 4 || d == 5 || d == 6) {
        if (!send_message_comm(client, "Left\n"))
            return false;
        if (!send_message_comm(client, "Left\n"))
            return false;
        return (send_message_comm(client, "Forward\n"));
    }
    return (go_to_broadcast_dir3(client, d));
}

bool go_to_broadcast_direction(client_t *client)
{
    size_t d = client->player->broadcast_direction;

    printf("%s[BROADCAST]%s broadcast capt %ld\n", Y, W, d);
    if (d == 0)
        return true;
    if (d == 1 || d == 2 || d == 8) {
        return (send_message_comm(client, "Forward\n"));
    }
    return (go_to_broadcast_dir2(client, d));
}

bool basic_command(client_t *client)
{
    if (client->pending_commands->lenght < 10 && !send_message(client->
        pending_commands, client->command, client->socket, "Look\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (client->pending_commands->lenght < 10 && !send_message(client->
        pending_commands, client->command, client->socket, "Inventory\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    if (client->player->fork == false && client->pending_commands->lenght < 10
        && !send_message(client->
        pending_commands, client->command, client->socket, "Connect_nbr\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
        return false;
    }
    return true;
}
