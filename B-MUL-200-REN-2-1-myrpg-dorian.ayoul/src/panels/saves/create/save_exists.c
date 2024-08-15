/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** save exists check
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>

bool save_exists(game_t *game, char *name)
{
    if (!game || !name)
        return (true);
    if (!game->saves)
        return (false);
    for (unsigned int itr = 0; game->saves[itr]; ++itr) {
        if (!nstrcmp(game->saves[itr]->name, name))
            return (true);
    }
    return (false);
}