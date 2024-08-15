/*
** EPITECH PROJECT, 2022
** server.c
** File description:
** server
*/

#include "server.h"

static size_t get_len_member(char **member)
{
    size_t i = 0;

    if (!member)
        return 0;
    while (member[i] != NULL)
        i++;
    return i;
}

static void split_add_member_in_team(team_t *team, char *name)
{
    size_t i = 0;

    team->member = realloc(team->member,
        sizeof(char *) * (get_len_member(team->member) + 2));
    while (team->member[i] != NULL)
        i++;
    team->member[i] = name;
    team->member[i + 1] = NULL;
}

bool add_member_in_team(team_t *team, char *name, char *team_id)
{
    team_t *save = team->head;

    for (team = team->head; team != NULL; team = team->next)
        if (strcmp(team_id, team->team_id) == 0)
            break;
    if (team == NULL) {
        team = save;
        return false;
    }
    if (!team->member) {
        team->member = malloc(sizeof(char *) * 2);
        team->member[0] = name;
        team->member[1] = NULL;
        return true;
    }
    split_add_member_in_team(team, name);
    return true;
}

int find_name_in_member(char **member, char *name)
{
    int i = 0;

    if (!member)
        return -1;
    while (member[i] != NULL) {
        if (strcmp(member[i], name) == 0)
            break;
        i++;
    }
    if (member[i] == NULL)
        return -1;
    return i;
}

bool remove_member_team(team_t *team, char *name, char *uuid)
{
    team_t *save = team->head;
    int i = 0;

    for (team = team->head; team != NULL; team = team->next)
        if (strcmp(team->team_id, uuid) == 0)
            break;
    if (team == NULL) {
        team = save;
        return false;
    }
    i = find_name_in_member(team->member, name);
    if (i == -1)
        return false;
    free(team->member[i]);
    team->member[i] = strdup("$");
    return true;
}
