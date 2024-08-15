/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef GAME_H
    #define GAME_H

    #include <stdio.h>
    #include <time.h>
    #include <sys/time.h>

    #include "list.h"

    #include "map.h"
    #include "trantorian.h"
    #include "team.h"
    #include "utils.h"

typedef struct {
    list_t *trantorians;
    size_t level;
    pos_t pos;
    size_t it_rem;
    const inventory_t *needed;
} incantation_t;

incantation_t *incantation_create(size_t level, pos_t pos);
void incantation_destroy(incantation_t *incantation);

typedef struct {
    size_t cli_per_team;
    size_t freq;
    list_t *teams;
    list_t *trantorians;
    map_t *map;
    list_t *incantations;
} game_t;

game_t *game_create(char **teams, size_t width, size_t height,
    size_t cli_per_team);
void game_destroy(game_t *game);

#endif // GAME_H
