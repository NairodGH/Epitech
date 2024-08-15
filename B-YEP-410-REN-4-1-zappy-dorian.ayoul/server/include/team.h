/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef TEAM_H
    #define TEAM_H

    #include <uuid/uuid.h>

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "list.h"
    #include "utils.h"

typedef struct {
    char *name;
    size_t cli_max;
    size_t cli_sub;
} team_t;

team_t *team_create(const char *name, size_t cli_max);
void team_destroy(team_t *team);

int team_init(list_t *teams_list, char **teams, size_t cli_max);

#endif // TEAM_H
