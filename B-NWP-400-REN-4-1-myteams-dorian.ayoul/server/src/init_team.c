/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** parser
*/

#include "server.h"

void add_team(team_t *team, char *name, char *id, char *description)
{
    team_t *new_team = NULL;

    if (!team->team_name) {
        team->head = team;
        team->next = NULL;
        team->team_id = id;
        team->team_name = name;
        team->description = description;
        return;
    }
    new_team = malloc(sizeof(team_t) * 1);
    new_team->head = team->head;
    new_team->description = description;
    new_team->team_name = name;
    new_team->member = NULL;
    new_team->team_id = id;
    new_team->next = NULL;
    for (team = team->head; team->next != NULL; team = team->next);
    team->next = new_team;
    team = team->head;
}

static team_t *create_empty_team(void)
{
    team_t *team = malloc(sizeof(team_t) * 1);

    team->team_name = NULL;
    team->team_id = NULL;
    team->description = NULL;
    team->member = NULL;
    team->head = team;
    team->next = NULL;
    return (team->head);
}

static void fill_team(team_t *team, char *buffer, size_t *i)
{
    char *id = get_word_message(buffer, i);
    char *name = get_word_message(buffer, i);
    char *description = get_word_message(buffer, i);
    char **member = get_list_member(buffer, i);

    add_team(team, name, id, description);
    if (!member)
        return;
    for (size_t n = 0; member[n] != NULL; n++)
        add_member_in_team(team, member[n], id);
    free(member);
}

static team_t *get_team(char *buffer, size_t size, int fd)
{
    team_t *team = create_empty_team();
    size_t ret = read(fd, buffer, size);
    size_t i = 0;

    if (ret < 10)
        return team;
    buffer[ret] = '\0';
    for (i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    if (buffer[i] == '\0' || buffer[i + 1] == '\0')
        return team;
    for (; buffer[i] != '[' && buffer[i] != '\0'; i++);
    for (; buffer[i] != '\0';) {
        if (buffer[i] == '[')
            i++;
        fill_team(team, buffer, &i);
        for (; buffer[i] != '\n' && buffer[i] != '\0'; (i)++);
        if (buffer[i] != '\0')
            i++;
    }
    return team;
}

team_t *load_team(void)
{
    int fd = open("database/team.txt", O_RDONLY);
    struct stat stats;
    char *buffer = NULL;
    team_t *team = NULL;

    if (fd == -1)
        return NULL;
    if (stat("database/team.txt", &stats) != 0) {
        close(fd);
        return NULL;
    }
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (!buffer) {
        close(fd);
        return NULL;
    }
    team = get_team(buffer, stats.st_size, fd);
    free(buffer);
    close(fd);
    return team;
}
