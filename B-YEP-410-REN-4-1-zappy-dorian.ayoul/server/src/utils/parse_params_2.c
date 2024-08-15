/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "core.h"

static int verif_params_2(args_t *args)
{
    if (args->freq <= 0) {
        fprintf(stderr, "[ERROR] Invalid frequency\n");
        return ERROR;
    }
    if (args->teams == NULL) {
        fprintf(stderr, "[ERROR] No team name\n");
        return ERROR;
    }
    return SUCCESS;
}

int verif_params(args_t *args)
{
    if (args->port <= 0) {
        fprintf(stderr, "[ERROR] Invalid port\n");
        return ERROR;
    }
    if ((args->width <= 0 || args->width > MAX_MAP_WIDTH) ||
            args->height <= 0 || args->height > MAX_MAP_HEIGHT) {
        fprintf(stderr, "[ERROR] Invalid size\n");
        return ERROR;
    }
    if (args->cli_per_team <= 0) {
        fprintf(stderr, "[ERROR] Invalid number of clients per team\n");
        return ERROR;
    }
    return verif_params_2(args);
}
