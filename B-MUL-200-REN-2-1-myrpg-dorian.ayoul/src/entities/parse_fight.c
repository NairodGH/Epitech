/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** parse_pos
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <errno.h>

PRIVATE void parse_path(entity_fight_t *fg, char **positions)
{
    unsigned int count = my_arrcount(positions);
    pos_t **pos = NULL;
    unsigned int itr = 0;
    char **nw = NULL;

    pos = ncalloc(count + 1, sizeof(pos_t));
    for (unsigned int jtr = 0; positions && positions[jtr]; ++jtr) {
        nw = my_strtok(xml_get_content(positions[jtr]), ',');
        if (!nw)
            continue;
        pos[itr] = ncalloc(1, sizeof(pos_t));
        pos[itr]->x = nw[0] ? natoi(nw[0]) : 0;
        pos[itr]->y = nw[1] ? natoi(nw[1]) : 0;
        ++itr;
    }
    pos[itr] = NULL;
    fg->pathing = pos;
}

entity_fight_t *parse_pathing(entity_fight_t *fg, char *fight_info)
{
    char *pathing = xml_get_balise(fight_info, "pathing");
    char *pos = xml_get_balise(pathing, "psts");
    char **positions;

    if (pathing == NULL || !pos) {
        fg->pathing = NULL;
        return (fg);
    }
    positions = xml_get_balises(pos, "position");
    if (!positions) {
        fg->pathing = NULL;
        return (fg);
    }
    fg->pathing_sleep = natoi(xml_get_attribute(pos, "sleep"));
    parse_path(fg, positions);
    return (fg);
}

entity_fight_t *parse_fight(char *fight_info)
{
    entity_fight_t *fight = ncalloc(1, sizeof(entity_fight_t));
    char *raw_health = xml_get_attribute(fight_info, "health");
    char *raw_defense = xml_get_attribute(fight_info, "defense");

    if (fight == NULL)
        return (NULL);
    fight->path_index = 0;
    fight->pathing_sleep = 0;
    fight->path_clock = sfClock_create();
    fight->health = natoi(raw_health);
    fight->defense = natoi(raw_defense);
    fight->skills = parse_skills(fight_info);
    fight = parse_pathing(fight, fight_info);
    return (fight);
}