/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Start cutscene
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

bool start_cutscene(game_t *game)
{
    if (!game || !game->cutscene)
        return (false);
    game->cutscene->in_cutscene = true;
    return (true);
}