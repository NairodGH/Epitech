/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_init
*/

#include <rpg/rpg.h>

void on_tick_fps(game_t *game)
{
    int fps = 0;

    while (true) {
        sfSleep((sfTime) {1000000});
        fps = game->curr_fps;
        game->curr_fps = 0;
        game->fps = fps;
    }
}

void start_fps(game_t *game)
{
    sfThread *th;

    if (!game)
        return;
    th = sfThread_create((void (*)(void *)) &on_tick_fps, game);
    sfThread_launch(th);
}