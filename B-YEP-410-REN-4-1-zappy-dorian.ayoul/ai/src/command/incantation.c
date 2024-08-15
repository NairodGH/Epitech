/*
** EPITECH PROJECT, 2022
** incantation.c
** File description:
** incantation ai
*/

#include "zappy_ai.h"

int incantation(client_t *client, char *str)
{
    char *save = str;

    client->player->incantation = false;
    if (strcmp(str, "Elevation underway") == 0) {
        client->player->incantation = true;
        client->player->broadcast_direction = -1;
        printf("%s[COMMAND]%s Incantation start\n", B, W);
        return 0;
    } else if (strlen(str) >= 14 && strncmp(str, "Current level:", 14) == 0) {
        printf("%s[COMMAND]%s Incantation done\n", G, W);
        save = go_next_chr(save, ':');
        if (save) {
            (char *)((size_t)(save++));
            client->player->level = atoi(save);
        }
        send_message_comm(client, "Forward\n");
        return 0;
    }
    printf("%s[COMMAND]%s Incantation fail\n", R, W);
    return 1;
}
