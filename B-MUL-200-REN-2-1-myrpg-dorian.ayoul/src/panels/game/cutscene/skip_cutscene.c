/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Skip cutscene
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

bool skip_cutscene(game_t *game)
{
    sfVector2i pos;

    if (!game || !game->cutscene)
        return (false);
    if (!game->cutscene->in_cutscene)
        return (false);
    game->cutscene->in_cutscene = false;
    pos = game->cutscene->end_pos;
    player_teleport(game, pos.x, pos.y);
    return (true);
}