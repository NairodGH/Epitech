/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** stage_free
*/

#include <rpg/rpg.h>

void stage_free(game_t *game)
{
    if (game->stage == NULL)
        return;
    map_free(game->stage->map);
    free(game->stage);
    game->stage = NULL;
}