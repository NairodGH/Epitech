/*
** EPITECH PROJECT, 2022
** tna.c
** File description:
** tna gui
*/

#include "zappy_gui.h"

int tna(client_t *client, char *str)
{
    char *team_name = NULL;
    char *save = str;

    if (strcmp(str, "suc\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s suc command received", R, W);
        return 1;
    }
    if (strcmp(str, "sbp\n") == 0) {
        fprintf(stderr, "%s[ERROR]%s bad arguments", R, W);
        return 1;
    }
    do {
        team_name = get_one_word(save);
        list_push_data(client->team, team_name);
    } while ((save = go_next_command(save, "tna")));
    print_team(client->team);
    return 0;
}
