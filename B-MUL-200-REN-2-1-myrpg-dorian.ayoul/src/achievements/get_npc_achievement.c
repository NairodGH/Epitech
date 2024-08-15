/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_npc_achievement
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

achievement_t *get_npc_achievement(game_t *gm, int n, enum achievement_type y)
{
    if (gm == NULL || gm->achievements == NULL)
        return (NULL);
    for (size_t itr = 0; gm->achievements[itr]; ++itr) {
        if (gm->achievements[itr]->npc_id != n)
            continue;
        if (get_achievement_type(gm->achievements[itr]) != y)
            continue;
        return (gm->achievements[itr]);
    }
    return (NULL);
}