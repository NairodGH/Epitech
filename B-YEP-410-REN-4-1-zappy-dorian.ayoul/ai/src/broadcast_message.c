/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast ai
*/

#include "zappy_ai.h"

void interpret_message(
    client_t *client, char *team_name, size_t direction, size_t level)
{
    if (level == 0)
        return;
    if (level == client->player->level &&
        strcmp(team_name, client->player->team_name) == 0)
        client->player->broadcast_direction = (int)direction;
}

bool message_broadcast(client_t *client, char *str)
{
    char *message = NULL;
    size_t direction = atoi(go_next_chr(str, ' '));
    char *save = go_next_chr(str, ',');
    size_t level = 0;

    (char *)((size_t)(save += 2));
    message = get_one_word(save);
    level = atoi(go_next_chr(save, ' '));
    if (!message) {
        fprintf(stderr, "%s[ERROR]%s Malloc error get_one_word\n", R, W);
        return false;
    }
    interpret_message(client, message, direction, level);
    free(message);
    return true;
}
