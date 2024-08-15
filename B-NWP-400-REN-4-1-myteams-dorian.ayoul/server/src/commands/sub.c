/*
** EPITECH PROJECT, 2022
** use.c
** File description:
** use
*/

#include "server.h"

static int split_sub(lcli_t *list, char **arg)
{
    if (get_len_arg(arg) != 1) {
        dprintf(list->client->fd, "500: <Error args>");
        return 1;
    }
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    return 0;
}

int subscribe(lcli_t *list, char **arg)
{
    team_t *save = list->client->all_team->head;

    if (split_sub(list, arg) == 1)
        return 1;
    for (list->client->all_team = list->client->all_team->head;
        list->client->all_team != NULL;
        list->client->all_team = list->client->all_team->next)
        if (strcmp(arg[0], list->client->all_team->team_id) == 0)
            break;
    if (!list->client->all_team) {
        dprintf(list->client->fd, "501: <[%s]>", arg[0]);
        list->client->all_team = save;
        return 1;
    }
    server_event_user_subscribed(arg[0], list->client->id);
    add_member_in_team(list->client->all_team->head,
        strdup(list->client->user_name), arg[0]);
    list->client->all_team = save;
    dprintf(list->client->fd, "208: <[%s][%s]>", list->client->id, arg[0]);
    return 0;
}

static bool find_uuid_team(team_t *team, char *uuid, char *name)
{
    team_t *save = team->head;
    int i = 0;

    for (; team != NULL; team = team->next) {
        if (strcmp(team->team_id, uuid) == 0)
            break;
    }
    if (team == NULL) {
        team = save;
        return false;
    }
    i = find_name_in_member(team->member, name);
    if (i == -1)
        return false;
    return true;
}

int unsubscribe(lcli_t *list, char **arg)
{
    team_t *save = list->client->all_team->head;

    if (split_sub(list, arg) == 1)
        return 1;
    if (!find_uuid_team(
        list->client->all_team->head, arg[0], list->client->user_name)) {
        dprintf(list->client->fd, "501: <[%s]>", arg[0]);
        list->client->all_team = save;
        return 1;
    }
    server_event_user_unsubscribed(arg[0], list->client->id);
    remove_member_team(
        list->client->all_team->head, list->client->user_name, arg[0]);
    list->client->all_team = save;
    dprintf(list->client->fd, "210: <[%s][%s]>", list->client->id, arg[0]);
    return 0;
}

int subscribed(lcli_t *list, char **arg)
{
    team_t *save = list->client->all_team->head;

    if (get_len_arg(arg) == 0) {
        for (team_t *temp = list->client->all_team->head;
            temp != NULL; temp = temp->next) {
            dprintf(list->client->fd, "209: <[%s][%s][%s]>",
                temp->team_id, temp->team_name, temp->description);
            usleep(5000);
        }
        return 0;
    }
    for (; save != NULL; save = save->next)
        if (strcmp(save->team_id, arg[0]) == 0)
            break;
    if (!save)
        return 1;
    print_arg(save->member);
    list->client->all_team = list->client->all_team->head;
    return 0;
}
