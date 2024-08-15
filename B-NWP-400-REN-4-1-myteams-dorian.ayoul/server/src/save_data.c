/*
** EPITECH PROJECT, 2022
** save_data.c
** File description:
** save_data
*/

#include "server.h"

static void print_all_member(char **member, int fd)
{
    if (!member) {
        dprintf(fd, "[]\n");
        return;
    }
    dprintf(fd, "[");
    for (size_t i = 0; member[i] != NULL; i++) {
        if (strcmp(member[i], "$") != 0)
            dprintf(fd, "{%s}", member[i]);
    }
    dprintf(fd, "]\n");
}

static void save_team(lcli_t *list)
{
    team_t *save = list->client->all_team->head;
    int fd = open("database/team.txt", O_WRONLY | O_TRUNC, 0700);

    if (!fd || list == NULL)
        return;
    list->client->all_team = list->client->all_team->head;
    dprintf(fd, "team :\n");
    while (list->client->all_team != NULL) {
        if (list->client->all_team->team_name != NULL) {
            dprintf(fd, "[%s] [%s] [%s] ",
            list->client->all_team->team_id, list->client->all_team->team_name,
            list->client->all_team->description);
            print_all_member(list->client->all_team->member, fd);
        }
        list->client->all_team = list->client->all_team->next;
    }
    list->client->all_team = save;
    close(fd);
}

static void save_message(lcli_t *list)
{
    messages_t *save = list->client->l_message->head;
    int fd = open("database/message.txt", O_WRONLY | O_TRUNC, 0700);

    if (!fd || list == NULL)
        return;
    list->client->l_message = list->client->l_message->head;
    dprintf(fd, "message :\n");
    while (list->client->l_message != NULL) {
        if (list->client->l_message->message != NULL) {
            dprintf(fd, "[%s] [%s] [%s] [%ld]\n",
            list->client->l_message->message, list->client->l_message->sender,
            list->client->l_message->receiver, list->client->l_message->time);
        }
        list->client->l_message = list->client->l_message->next;
    }
    list->client->l_message = save;
    close(fd);
}

void save_data(lcli_t *list)
{
    lcli_t *save = list;
    int fd = open("database/client.txt", O_WRONLY | O_TRUNC, 0700);

    if (!fd)
        return;
    dprintf(fd, "Id\t\t\t\tUserName\n");
    while (list != NULL) {
        if (list->client->user_name != NULL) {
            dprintf(fd, "%s\t\t\t%s\n",
                list->client->id, list->client->user_name);
        } else
            dprintf(fd, "(null)\t\t\t(null)\n");
        list = list->next;
    }
    close(fd);
    save_message(save->head);
    save_team(save->head);
}
