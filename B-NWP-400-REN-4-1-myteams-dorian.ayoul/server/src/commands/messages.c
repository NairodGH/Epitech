/*
** EPITECH PROJECT, 2022
** list.c
** File description:
** list
*/

#include "server.h"

size_t get_len_message(lcli_t *list, char *receiver, char *sender)
{
    messages_t *save = list->client->l_message->head;
    size_t ret = 0;

    for (list->client->l_message = list->client->l_message->head;
        list->client->l_message != NULL;
        list->client->l_message = list->client->l_message->next) {
        if (list->client->l_message->receiver
        && list->client->l_message->sender
        && (strcmp(list->client->l_message->receiver, receiver) == 0
        || strcmp(list->client->l_message->receiver, sender) == 0)
        && (strcmp(list->client->l_message->sender, receiver) == 0
        || strcmp(list->client->l_message->sender, sender) == 0)) {
            ret++;
        }
    }
    list->client->l_message = save;
    return ret;
}

static void fill_info_mes(messages_t *l_mess, char *mess, char *sd, char *time)
{
    char *temp = my_ltoa(l_mess->time);

    strcat(mess, l_mess->message);
    strcat(mess, "|");
    strcat(sd, l_mess->sender);
    strcat(sd, "|");
    strcat(time, temp);
    strcat(time, "|");
    free(temp);
}

static int free_info(char *message, char *sender, char *timest, lcli_t *list)
{
    printf("message = %s\n", message[0] == '\0' ? NULL : message);
    dprintf(list->client->fd, "204: <[%s][%s][%s]>", sender, timest, message);
    free(message);
    free(sender);
    free(timest);
    return 0;
}

static int split_messages(lcli_t *list, char *rc, char *my_sender)
{
    messages_t *save = list->client->l_message->head;
    messages_t *l_mess = list->client->l_message->head;
    size_t len_list = get_len_message(list->head, rc, my_sender);
    char *message = calloc(len_list * (MAX_BODY_LENGTH + 1) + 1, sizeof(char));
    char *sender = calloc(len_list * (UUID_STR_LEN + 2) + 1, sizeof(char));
    char *timest = calloc(len_list * (10 + 3) + 1, sizeof(char));

    if (len_list == 0)
        return (free_info(message, sender, timest, list));
    for (l_mess = l_mess->head; l_mess != NULL; l_mess = l_mess->next)
        if (l_mess->receiver && l_mess->sender && (!strcmp(l_mess->receiver, rc)
            || strcmp(l_mess->receiver, my_sender) == 0)
            && (strcmp(l_mess->sender, rc) == 0
            || strcmp(l_mess->sender, my_sender) == 0))
            fill_info_mes(l_mess, message, sender, timest);
    message[strlen(message) - 1] = '\0';
    sender[strlen(sender) - 1] = '\0';
    timest[strlen(timest) - 1] = '\0';
    l_mess = save;
    return (free_info(message, sender, timest, list));
}

int messages(lcli_t *list, char **arg)
{
    lcli_t *save = list;
    bool valid = false;

    if (arg == NULL || get_len_arg(arg) != 1) {
        dprintf(list->client->fd, "500: <Error args>");
        return 1;
    }
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    for (list = list->head; list != NULL; list = list->next)
        if (list->client->id != NULL && strcmp(list->client->id, arg[0]) == 0)
            valid = true;
    list = save;
    if (!valid) {
        dprintf(save->client->fd, "501: <[%s]>", arg[0]);
        return 1;
    }
    return (split_messages(list, arg[0], list->client->id));
}
