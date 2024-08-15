/*
** EPITECH PROJECT, 2022
** broadcast.c
** File description:
** broadcast gui
*/

#include "zappy_gui.h"

int pdi(client_t *client, char *str)
{
    node_t *other = NULL;
    node_t *save = NULL;
    char *uuid = get_one_word(str);

    !uuid ? (uuid = strdup("0")) : 0;
    foreach_safe(client->player->head, other, save)
        if (strcmp(((player_t *)other->data)->uuid, uuid) == 0) {
            list_remove_node(client->player, other);
            list_remove_node(client->map[((player_t *)other->data)->pos.y]
                [((player_t *)other->data)->pos.x].player, other);
            list_destroy_node(other, free_player);
            break;
        }
    free(uuid);
    return 0;
}
