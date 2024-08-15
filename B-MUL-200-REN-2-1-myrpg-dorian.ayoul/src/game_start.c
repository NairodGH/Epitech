/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_start
*/

#include <rpg/rpg.h>

void game_start(list_t *args)
{
    game_t game;

    game_init(&game, args);
    game_exit(&game, NULL);
}