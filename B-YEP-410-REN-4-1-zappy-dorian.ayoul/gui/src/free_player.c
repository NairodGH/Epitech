/*
** EPITECH PROJECT, 2022
** create_client.c
** File description:
** create_client gui
*/

#include "zappy_gui.h"

void free_player(void *data)
{
    player_t *player = data;

    if (player) {
        free(player->uuid);
        free(player);
        player = NULL;
    }
}
