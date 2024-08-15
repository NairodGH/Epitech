/*
** EPITECH PROJECT, 2022
** create
** File description:
** create.c
*/

#include "server.h"

static int create_comment(lcli_t *list, char **arg)
{
    char *timestamp = NULL;

    if (get_len_arg(arg) != 1 || strlen(arg[0]) > MAX_BODY_LENGTH) {
        dprintf(list->client->fd, "500: <Error args>");
        reset_context(list->context);
        return 1;
    }
    timestamp = my_ltoa(time(NULL));
    server_event_reply_created(list->context->thread, list->client->id, arg[0]);
    dprintf(list->client->fd, "211: <[reply][%s][%s][%s][%s]>",
        list->context->comment, list->client->id, timestamp, arg[0]);
    free(list->context->channel_name);
    free(list->context->thread);
    free(list->context->comment);
    free(timestamp);
    reset_context(list->context);
    return 0;
}

static int create_thread(lcli_t *list, char **arg)
{
    char *id = NULL;
    char *timestamp = NULL;

    if (get_len_arg(arg) != 2 || strlen(arg[1]) > MAX_BODY_LENGTH) {
        dprintf(list->client->fd, "500: <Error args>");
        reset_context(list->context);
        return 1;
    }
    id = generate_id();
    timestamp = my_ltoa(time(NULL));
    server_event_thread_created(list->context->channel_name,
        list->context->thread, list->client->id, arg[0], arg[1]);
    dprintf(list->client->fd, "211: <[thread][%s][%s][%s][%s][%s]>", id,
        list->client->id, timestamp, arg[0], arg[1]);
    free(list->context->channel_name);
    free(list->context->thread);
    free(id);
    free(timestamp);
    reset_context(list->context);
    return 0;
}

static int create_channel(lcli_t *list, char **arg)
{
    char *id = NULL;

    if (get_len_arg(arg) != 2 || strlen(arg[1]) > MAX_DESCRIPTION_LENGTH) {
        dprintf(list->client->fd, "500: <Error args>");
        reset_context(list->context);
        return 1;
    }
    id = generate_id();
    server_event_channel_created(list->context->channel_name, arg[0], id);
    dprintf(list->client->fd, "211: <[channel][%s][%s][%s]>",
        id, arg[0], arg[1]);
    free(list->context->channel_name);
    free(id);
    reset_context(list->context);
    return 0;
}

static int create_team(lcli_t *list, char **arg)
{
    char *id = NULL;

    if (get_len_arg(arg) != 2 || strlen(arg[1]) > MAX_DESCRIPTION_LENGTH) {
        dprintf(list->client->fd, "500: <Error args>");
        reset_context(list->context);
        return 1;
    }
    id = generate_id();
    if (!id) {
        reset_context(list->context);
        return 1;
    }
    server_event_team_created(id, arg[0], list->client->id);
    dprintf(list->client->fd, "211: <[team][%s][%s][%s]>", id, arg[0], arg[1]);
    add_team(list->client->all_team, strdup(arg[0]), id, strdup(arg[1]));
    reset_context(list->context);
    return 1;
}

int create(lcli_t *list, char **arg)
{
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    if (list->context->thread == NULL && list->context->channel_name == NULL
        && list->context->comment == NULL)
        return (create_team(list, arg));
    if (list->context->channel_name != NULL && list->context->thread == NULL
        && list->context->comment == NULL)
        return (create_channel(list, arg));
    if (list->context->channel_name != NULL && list->context->thread != NULL
        && list->context->comment == NULL)
        return (create_thread(list, arg));
    if (list->context->comment != NULL)
        return (create_comment(list, arg));
    return 0;
}
