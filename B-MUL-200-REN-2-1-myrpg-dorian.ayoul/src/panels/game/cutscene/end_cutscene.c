/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** End cutscene
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

bool end_cutscene(game_t *game)
{
    if (!game || !game->cutscene)
        return (false);
    game->cutscene->in_cutscene = false;
    return (true);
}