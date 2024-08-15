/*
** EPITECH PROJECT, 2022
** login.c
** File description:
** login
*/

#include "server.h"

static bool already_exist(lcli_t *list, lcli_t *save, char **arg)
{
    if (list->client->user_name == NULL)
        return false;
    if (strcmp(list->client->user_name, arg[0]) == 0) {
        if (list->client->id != save->client->id) {
            free(save->client->id);
            save->client->id = NULL;
        }
        list->client->fd = save->client->fd;
        list->client->is_login = true;
        server_event_user_logged_in(list->client->id);
        dprintf(save->client->fd, "201: <[%s][%s]>",
            list->client->id, list->client->user_name);
        return true;
    }
    return false;
}

int login(lcli_t *list, char **arg)
{
    lcli_t *save = list;

    if (get_len_arg(arg) < 1) {
        dprintf(list->client->fd, "500: <Error args>");
        return 1;
    }
    if (strlen(arg[0]) > MAX_BODY_LENGTH) {
        dprintf(list->client->fd, "500: <Name too big>");
        return 1;
    }
    save->client->is_login = true;
    for (list = list->head; list != NULL; list = list->next)
        if (already_exist(list, save, arg))
            return 0;
    save->client->user_name = strdup(arg[0]);
    dprintf(save->client->fd, "201: <[%s][%s]>",
        save->client->id, save->client->user_name);
    server_event_user_created(save->client->id, save->client->user_name);
    server_event_user_logged_in(save->client->id);
    return 0;
}

int logout(lcli_t *list, __attribute__((unused)) char **arg)
{
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    server_event_user_logged_out(list->client->id);
    list->client->is_login = false;
    dprintf(list->client->fd, "202: <[%s][%s]>",
        list->client->id, list->client->user_name);
    return 0;
}
