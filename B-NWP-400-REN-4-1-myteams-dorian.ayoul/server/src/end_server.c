/*
** EPITECH PROJECT, 2022
** save_data.c
** File description:
** save_data
*/

#include "server.h"

static void clear_member(char **member)
{
    if (member) {
        for (size_t i = 0; member[i] != NULL; i++)
            free(member[i]);
        free(member);
    }
}

void clear_team(team_t *team)
{
    team_t *temp = NULL;

    if (!team)
        return;
    team = team->head;
    while (team != NULL) {
        temp = team;
        clear_member(team->member);
        if (team->team_id != NULL)
            free(team->team_id);
        if (team->team_name != NULL)
            free(team->team_name);
        if (team->description != NULL)
            free(team->description);
        if (team->next == NULL)
            break;
        team = team->next;
        free(temp);
    }
    free(team);
}

void clear_message(messages_t *message)
{
    messages_t *temp = NULL;

    if (!message)
        return;
    message = message->head;
    while (message != NULL) {
        temp = message;
        if (message->message != NULL)
            free(message->message);
        if (message->sender != NULL)
            free(message->sender);
        if (message->receiver != NULL)
            free(message->receiver);
        if (message->next == NULL)
            break;
        message = message->next;
        free(temp);
    }
    free(message);
}

void end_server(server_t *serv, lcli_t *list)
{
    clear_message(list->client->l_message);
    clear_team(list->client->all_team);
    free(list->context);
    clear_client(list, serv);
    destroy_socket(serv->socket);
}