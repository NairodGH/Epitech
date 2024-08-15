/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "team.h"

static int is_team_same(char **teams, size_t to_comp)
{
    for (size_t j = 0; teams != NULL && teams[j] != NULL; j++) {
        if (j != to_comp && strcmp(teams[to_comp], teams[j]) == 0) {
            return ERROR;
        }
    }
    return SUCCESS;
}

static int team_compare(char **teams)
{
    size_t i = 0;

    for (; teams != NULL && teams[i] != NULL; i++) {
        if (is_team_same(teams, i) == ERROR) {
            return ERROR;
        }
    }
    if (i < 1)
        return ERROR;
    return SUCCESS;
}

int team_init(list_t *teams_list, char **teams, size_t cli_max)
{
    team_t *team = NULL;

    if (team_compare(teams) == ERROR)
        return ERROR;
    for (size_t i = 0; teams && teams[i]; i++) {
        team = team_create(teams[i], cli_max);
        if (team == NULL)
            return ERROR;
        if (list_push_data(teams_list, team) == LIST_FAILURE)
            return ERROR;
    }
    return SUCCESS;
}

team_t *team_create(const char *name, size_t cli_max)
{
    team_t *team = calloc(1, sizeof(team_t));

    if (team == NULL)
        return NULL;
    team->name = strdup(name);
    if (team->name == NULL)
        return NULL;
    team->cli_max = cli_max;
    return team;
}

void team_destroy(team_t *team)
{
    if (team == NULL)
        return;
    if (team->name)
        free(team->name);
    free(team);
}
