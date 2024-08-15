/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "game.h"

game_t *game_create(char **teams, size_t width, size_t height,
    size_t cli_per_team)
{
    game_t *game = calloc(1, sizeof(game_t));

    if (game == NULL)
        return NULL;
    game->cli_per_team = cli_per_team;
    game->teams = list_create();
    game->trantorians = list_create();
    game->incantations = list_create();
    game->map = map_create(width, height);
    if (!game->teams || !game->trantorians || !game->map ||
            !game->incantations) {
        game_destroy(game);
        return NULL;
    }
    if (team_init(game->teams, teams, cli_per_team) == ERROR) {
        game_destroy(game);
        return NULL;
    }
    return game;
}

void game_destroy(game_t *game)
{
    if (game == NULL)
        return;
    if (game->teams)
        list_destroy(game->teams, (void (*)(void *))team_destroy);
    if (game->trantorians)
        list_destroy(game->trantorians, (void (*)(void *))trantorian_destroy);
    if (game->map)
        map_destroy(game->map);
    free(game);
}
