/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *command_tna_write_team_name(core_t *core, client_t *client,
    char *team_name)
{
    char *buff = NULL;

    if (asprintf(&buff, "tna %s\n", team_name) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        command_suc(core, client);
        return NULL;
    }
    return buff;
}

static char *get_buffer(char *buffer, char *tmp)
{
    char *save_buff = NULL;

    save_buff = buffer;
    if (asprintf(&buffer, "%s%s", buffer ? buffer : "", tmp) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        free(tmp);
        return NULL;
    }
    if (save_buff)
        free(save_buff);
    return buffer;
}

void command_tna(core_t *core, client_t *client, UNUSED char *command)
{
    node_t *node = NULL;
    char *buffer = NULL;
    char *tmp = NULL;

    foreach(core->game->teams->head, node) {
        tmp = command_tna_write_team_name(core, client,
            ((team_t *)node->data)->name);
        if (tmp == NULL)
            continue;
        buffer = get_buffer(buffer, tmp);
        if (buffer == NULL)
            continue;
        free(tmp);
    }
    client_push_command(core->server, client, buffer);
}
