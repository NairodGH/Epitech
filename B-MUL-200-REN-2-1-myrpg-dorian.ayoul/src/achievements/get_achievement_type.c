/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_achievement_type
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

enum achievement_type get_achievement_type(achievement_t *achievement)
{
    char *type;

    if (achievement == NULL)
        return (UNKNOWN_ACHIEVEMENT);
    type = achievement->type;
    if (!nstrcmp(type, "DISCUSS_NPC"))
        return (DISCUSS_NPC);
    if (!nstrcmp(type, "QUEST_NPC"))
        return (QUEST_NPC);
    if (!nstrcmp(type, "FIGHT_NPC"))
        return (FIGHT_NPC);
    return (UNKNOWN_ACHIEVEMENT);
}