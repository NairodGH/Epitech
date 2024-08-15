/*
** EPITECH PROJECT, 2022
** if_forest.c
** File description:
** if_forest ai
*/

#include "zappy_ai.h"

bool get_object(client_t *client, size_t nb, size_t needed, char *object)
{
    int nb_food = needed - nb;
    char *name = calloc(1, sizeof(char) * (7 + strlen(object)));

    if (!name) {
        fprintf(stderr, "%s[ERROR]%s Malloc error get_nb_object\n", R, W);
        return false;
    }
    nb_food > 0 ? strcat(name, "Take ") : strcat(name, "Set ");
    strcat(strcat(name, object), "\n");
    while (nb_food != 0 && client->pending_commands->lenght < 10) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, name)) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            free(name);
            return false;
        }
        nb_food > 0 ? nb_food-- : nb_food++;
    }
    free(name);
    return true;
}

bool get_food_in_cell(client_t *client, size_t x, size_t y)
{
    size_t nb_food = client->map[y][x].inv->food;

    while (nb_food != 0 && client->pending_commands->lenght < 10) {
        if (!send_message(client->pending_commands,
            client->command, client->socket, "Take food\n")) {
            fprintf(stderr, "%s[ERROR]%s Malloc error send_message\n", R, W);
            return false;
        }
        nb_food--;
    }
    return true;
}

bool try_evoluate(client_t *client)
{
    if (!client->player->inv || client->player->incantation)
        return true;
    if (client->player->level == 1)
        return (level_1(client));
    if (client->player->level == 2)
        return (level_2(client));
    if (client->player->level == 3)
        return (level_3(client));
    if (client->player->level == 4)
        return (level_4(client));
    if (client->player->level == 5)
        return (level_5(client));
    if (client->player->level == 6)
        return (level_6(client));
    if (client->player->level == 7)
        return (level_7(client));
    return true;
}

bool remove_surplus_command(client_t *client)
{
    char *command = NULL;

    while (client->pending_commands->lenght > 10) {
        command = list_pop_last(client->pending_commands);
        printf("%s[INFO]%s remove command : %s\n", M, W, command);
        free(command);
    }
    if (!basic_command(client))
        return false;
    if (client->unused_slot == 0 && client->player->fork == false) {
        client->player->fork = true;
        if (!send_message_comm(client, "Fork\n"))
            return false;
    }
    return true;
}

bool robot(client_t *client)
{
    if (!client->player->inv)
        return true;
    if (client->player->inv->food < 2) {
        client->player->incantation = false;
        if (!get_food_basic(client))
            return false;
        return true;
    }
    if (client->player->incantation)
        return (send_message_comm(client, "Inventory\n"));
    if (client->player->inv && client->player->inv->food < 5) {
        if (!get_food_basic(client))
            return false;
    } else if (client->player->broadcast_direction != -1) {
        go_to_broadcast_direction(client);
        client->player->broadcast_direction = -1;
    } else
        try_evoluate(client);
    return remove_surplus_command(client);
}
