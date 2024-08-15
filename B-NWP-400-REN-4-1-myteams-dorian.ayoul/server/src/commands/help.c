/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** help
*/

#include "server.h"

int help(lcli_t *list, __attribute__((unused)) char **arg)
{
    dprintf(list->client->fd, "200: <[/help : show help\n"
        "login {“user_name”} : set the user_name used by client\n"
        "/logout : disconnect the client from the server\n"
        "/users : get the list of all users that exist on the domain\n"
        "/user {“user_uuid”} : get information about a user\n"
        "/send {“user_uuid”} [“message_body”} : send a message to a user\n"
        "/messages {“user_uuid”} : list all messages exchange with an user\n"
        "/subscribe {“team_uuid”} : subscribe to the event of a team and its "
        "sub directories (enable receptionof all events from a team)\n"
        "/subscribed ?{“team_uuid”} : list all subscribed teams or list all "
        "users subscribed to a team\n"
        "/unsubscribe {“team_uuid”} : unsubscribe from a team\n"
        "/use ?{“team_uuid”} ?{“channel_uuid”} ?{“thread_uuid”} : "
        "use specify a context team/channel/thread\n"
        "/create : based on what is being used create the sub resource "
        "(see below)\n"
        "/list : based on what is being used list all the sub resources "
        "(see below)\n"
        "/info : based on what is being used list the current (see below)]>");
    return 0;
}

int use(lcli_t *list, char **arg)
{
    if (!arg) {
        list->context->team = true;
        return 0;
    }
    if (get_len_arg(arg) == 1)
        list->context->channel_name = strdup(arg[0]);
    if (get_len_arg(arg) == 2) {
        list->context->channel_name = strdup(arg[0]);
        list->context->thread = strdup(arg[1]);
    }
    if (get_len_arg(arg) == 3) {
        list->context->channel_name = strdup(arg[0]);
        list->context->thread = strdup(arg[1]);
        list->context->comment = strdup(arg[2]);
    }
    dprintf(list->client->fd, "use");
    return 0;
}

static int add_message_in_list(lcli_t *list, lcli_t *save, char **arg)
{
    dprintf(list->client->fd, "203: <[%s][%s]>", list->client->id, arg[1]);
    server_event_private_message_sended(
        save->client->id, list->client->id, arg[1]);
    add_message(list->client->l_message->head,
        strdup(arg[1]), strdup(save->client->id), strdup(list->client->id));
    return 0;
}

int my_send(lcli_t *list, char **arg)
{
    lcli_t *save = list;

    if (arg == NULL || get_len_arg(arg) != 2) {
        dprintf(list->client->fd, "500: <Error args>");
        return 1;
    }
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    for (list = list->head; list != NULL; list = list->next) {
        if (!list->client->id)
            continue;
        if (strcmp(list->client->id, arg[0]) == 0)
            break;
    }
    if (list == NULL)
        return dprintf(save->client->fd, "501: <[%s]>", arg[0]) * 0 + 1;
    return (add_message_in_list(list, save, arg));
}

char *array_to_string(char **list_message)
{
    char *message = NULL;
    size_t total_len = 0;

    if (list_message == NULL || list_message[0] == NULL)
        return strdup("No message");
    for (size_t i = 0; list_message[i] != NULL; i++)
        total_len += strlen(list_message[i]) + 1;
    message = malloc(sizeof(char) * (total_len + 1));
    if (!message)
        return NULL;
    for (size_t i = 0; list_message[i] != NULL; i++) {
        strcat(message, list_message[i]);
        strcat(message, "\n");
    }
    message[strlen(message) - 1] = '\0';
    return message;
}
