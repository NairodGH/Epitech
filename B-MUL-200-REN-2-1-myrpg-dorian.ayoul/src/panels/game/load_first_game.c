/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Load fist game
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void load_first_game(ENGPANEL)
{
    if (!game)
        return;
    if (!game->first_game)
        return;
    start_cutscene(game);
    game->first_game = false;
}