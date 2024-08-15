/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

args_t *init_args(void)
{
    args_t *args = calloc(1, sizeof(args_t));

    if (args == NULL)
        return NULL;
    args->port = DEFAULT_PORT;
    args->width = DEFAULT_WIDTH;
    args->height = DEFAULT_HEIGHT;
    args->cli_per_team = 1;
    args->freq = DEFAULT_FREQ;
    return args;
}

void destroy_args(args_t *args)
{
    if (args == NULL)
        return;
    free(args->teams);
    free(args);
}

core_t *core_create(void)
{
    return calloc(1, sizeof(core_t));
}

void core_destroy(core_t *core)
{
    if (core == NULL)
        return;
    if (core->game != NULL)
        game_destroy(core->game);
    if (core->server != NULL)
        server_destroy(core->server);
    free(core);
}
