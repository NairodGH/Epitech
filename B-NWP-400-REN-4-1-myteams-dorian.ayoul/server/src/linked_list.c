/*
** EPITECH PROJECT, 2022
** linked_list.c
** File description:
** linked_list
*/

#include "server.h"

int count_nb_clients(lcli_t *list)
{
    size_t i = 0;

    while (list != NULL) {
        if (list->client->id != NULL)
            i++;
        list = list->next;
    }
    return i;
}

static lcli_t *create_head(clients_t *list_client, context_t *context)
{
    lcli_t *head = malloc(sizeof(lcli_t) * 1);

    if (!head)
        return NULL;
    head->prev = NULL;
    head->next = NULL;
    head->head = head;
    head->client = list_client;
    head->context = context;
    return head;
}

static lcli_t *create_node(
    lcli_t *head, clients_t *list_client, lcli_t *last, context_t *context)
{
    lcli_t *node = malloc(sizeof(lcli_t) * 1);

    if (!node)
        return NULL;
    node->next = NULL;
    node->prev = last;
    node->head = head;
    node->context = context;
    node->client = list_client;
    return node;
}

void reset_context(context_t *context)
{
    context->team = false;
    context->channel_name = NULL;
    context->thread = NULL;
    context->comment = NULL;
}

lcli_t *create_list(clients_t *list_client)
{
    size_t i = 1;
    context_t *context = malloc(sizeof(context_t) * 1);
    lcli_t *head = NULL;
    lcli_t *node = NULL;
    lcli_t *last = NULL;

    reset_context(context);
    head = create_head(&list_client[0], context);
    if (!head)
        return NULL;
    node = head;
    while (i != MAX_CLIENT) {
        last = node;
        node->next = create_node(head, &list_client[i], last, context);
        if (!node->next)
            return NULL;
        node = node->next;
        i++;
    }
    return head;
}
