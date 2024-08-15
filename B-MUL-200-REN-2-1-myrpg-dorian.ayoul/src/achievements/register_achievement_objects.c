/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** register_achievement_objects
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

void register_achievement_objects(game_t *game, panel_t *panel)
{
    if (game == NULL || panel == NULL)
        return;
    if (game->achievements == NULL)
        return;
    for (unsigned int itr = 0; game->achievements[itr]; ++itr) {
        if (game->achievements[itr]->obj == NULL)
            continue;
        register_object(panel, game->achievements[itr]->obj);
    }
}