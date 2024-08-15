/*
** EPITECH PROJECT, 2022
** loop_command.c
** File description:
** loop_command gui
*/

#include "zappy_gui.h"

static bool send_message_comm(client_t *client, char *com)
{
    if (!send_message(
        client->pending_commands, client->command, client->socket, com)) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    }
    return true;
}

bool find_command(client_t *client, char *temp)
{
    char *save = temp;
    char *comm = NULL;

    while (save[0] != '\0') {
        if (!(comm = get_one_command(save)))
            return false;
        if (!parse_return(client, comm)) {
            free(temp);
            return true;
        }
        save = go_next_char(save, '\n');
        free(comm);
        if (!save)
            break;
    }
    free(temp);
    return true;
}

void free_string(char *pin, char *plv, char *pl)
{
    free(pl);
    free(pin);
    free(plv);
}

static bool players_command(client_t *client)
{
    node_t *node = NULL;
    char *pl = NULL;
    char *pin = NULL;
    char *plv = NULL;
    char *uuid = NULL;

    foreach (client->player->head, node) {
        uuid = ((player_t *)node->data)->uuid;
        pl = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        pin = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        plv = calloc(1, sizeof(char) * (strlen(uuid) + 10));
        strcat(strcat(strcat(pl, "ppo #"), uuid), "\n");
        strcat(strcat(strcat(pin, "pin #"), uuid), "\n");
        strcat(strcat(strcat(plv, "plv #"), uuid), "\n");
        if (!send_message_comm(client, pl) || !send_message_comm(client, pin)
            || !send_message_comm(client, plv))
            return false;
        free_string(pl, pin, plv);
    }
    return true;
}

bool loop_command(client_t *client)
{
    static size_t remaining = 0;

    if (remaining > 0) {
        remaining--;
    } else if (!send_message(
        client->pending_commands, client->command, client->socket, "mct\n")) {
        fprintf(stderr, "%s[ERROR]%s Malloc error send_message", R, W);
        return false;
    } else {
        remaining = MAP_REFRESH + client->size_map.x / 6 +
            client->size_map.y / 6;
    }
    if (!players_command(client))
        return false;
    return true;
}
