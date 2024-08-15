/*
** EPITECH PROJECT, 2022
** message_list.c
** File description:
** message_list
*/

#include "server.h"

static char *spl_list_to_string_id(
    messages_t *l_message, char *sender, char *receiver, size_t s)
{
    messages_t *save = l_message->head;
    char *buffer = malloc(sizeof(char) * (s + 2));

    if (!buffer)
        return NULL;
    buffer[0] = '\0';
    while (l_message != NULL) {
        if ((strcmp(l_message->receiver, receiver) == 0
        || strcmp(l_message->receiver, sender) == 0)
        && (strcmp(l_message->sender, receiver) == 0
        || strcmp(l_message->sender, sender) == 0)) {
            strcat(buffer, l_message->message);
            strcat(buffer, "\n");
        }
        l_message = l_message->next;
    }
    strcat(buffer, "\0");
    l_message = save;
    return buffer;
}

char *list_to_string_id(messages_t *l_message, char *sender, char *receiver)
{
    messages_t *save = l_message->head;
    size_t s = 0;

    if (!l_message || !l_message->head)
        return NULL;
    l_message = l_message->head;
    while (l_message != NULL) {
        if ((strcmp(l_message->receiver, receiver) == 0
        || strcmp(l_message->receiver, sender) == 0)
        && (strcmp(l_message->sender, receiver) == 0
        || strcmp(l_message->sender, sender) == 0))
            s += (strlen(l_message->message) + 1);
        l_message = l_message->next;
    }
    if (s == 0)
        return NULL;
    l_message = save;
    return (spl_list_to_string_id(l_message, sender, receiver, s));
}

void add_message(messages_t *l_message,
    char *message, char *sender, char *receiver)
{
    messages_t *new_message = NULL;

    if (l_message->message == NULL) {
        l_message->message = message;
        l_message->sender = sender;
        l_message->receiver = receiver;
        l_message->time = (time_t)time(NULL);
        l_message->next = NULL;
        return;
    }
    new_message = malloc(sizeof(messages_t) * 1);
    new_message->message = message;
    new_message->sender = sender;
    new_message->receiver = receiver;
    new_message->head = new_message;
    new_message->next = l_message;
    new_message->time = (time_t)time(NULL);
    for (; l_message != NULL; l_message = l_message->next)
        l_message->head = new_message;
    l_message = new_message->head;
}

messages_t *create_empty_message(void)
{
    messages_t *new_message = malloc(sizeof(messages_t) * 1);

    new_message->message = NULL;
    new_message->sender = NULL;
    new_message->receiver = NULL;
    new_message->head = new_message;
    new_message->time = 0;
    new_message->next = NULL;
    return (new_message->head);
}
