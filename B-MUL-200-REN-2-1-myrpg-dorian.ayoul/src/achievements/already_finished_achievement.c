/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** finish_achievement
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

bool already_finished_achievement(game_t *game, int id)
{
    char *ach;

    if (game == NULL || game->player == NULL)
        return (false);
    ach = game->player->achievements;
    if (!ach)
        return (false);
    for (unsigned int itr = 0; ach[itr]; ++itr) {
        if (ach[itr] == ',')
            continue;
        if (ach[itr] - '0' == id)
            return (true);
    }
    return (false);
}