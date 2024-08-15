/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Is cutscene started
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

bool is_cutscene_started(game_t *game)
{
    if (!game || !game->cutscene)
        return (false);
    return (game->cutscene->in_cutscene);
}