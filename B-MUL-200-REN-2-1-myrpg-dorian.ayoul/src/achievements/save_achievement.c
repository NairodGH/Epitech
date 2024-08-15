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

PRIVATE char *update_achievement_list(game_t *game, int id)
{
    char *ach = game->player->achievements;
    char *new;
    int itr;
    int len;

    if (!ach)
        return (NULL);
    len = nstrlen(ach) + 3;
    new = ncalloc(len, sizeof(char));
    if (!new)
        return (NULL);
    for (itr = 0; ach[itr]; ++itr)
        new[itr] = ach[itr];
    new[itr++] = id + '0';
    new[itr++] = ',';
    new[itr] = '\0';
    return (new);
}

void save_achievement(game_t *game, int id)
{
    char *new = NULL;

    if (game == NULL || game->player == NULL)
        return;
    new = update_achievement_list(game, id);
    game->player->achievements = new;
}