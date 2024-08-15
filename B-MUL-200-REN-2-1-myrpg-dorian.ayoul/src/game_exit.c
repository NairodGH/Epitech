/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_init
*/

#include <rpg/rpg.h>

PRIVATE void game_free(game_t *game)
{
    stage_free(game);
    tilesets_free(game->tilesets);
    if (game->window != NULL) {
        destroy_window(game->window);
        sfRenderWindow_destroy(game->window->window);
        game->window = NULL;
    }
}

void game_exit(game_t *game, char const *message)
{
    if (message)
        nprintf(message);
    game_free(game);
}