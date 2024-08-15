/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *concat_tiles_content(core_t *core, client_t *client,
    char *buffer, size_t i)
{
    char *temp = NULL;
    char *save_buff = NULL;

    for (size_t j = 0; j < core->game->map->width; j++) {
        temp = command_write_tile_content(core, client, j, i);
        if (temp == NULL)
            continue;
        save_buff = buffer;
        if (asprintf(&buffer, "%s%s", buffer ? buffer : "", temp) == -1) {
            fprintf(stderr, "[ERROR] GUI Can't malloc\n");
            free(temp);
            continue;
        }
        if (save_buff)
            free(save_buff);
        free(temp);
    }
    return buffer;
}

void command_mct(core_t *core, client_t *client, UNUSED char *command)
{
    char *buffer = NULL;

    for (size_t i = 0; i < core->game->map->height; i++) {
        buffer = concat_tiles_content(core, client, buffer, i);

    }
    client_push_command(core->server, client, buffer);
}
