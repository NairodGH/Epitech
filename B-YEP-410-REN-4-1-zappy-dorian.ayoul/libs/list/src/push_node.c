/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main
*/

#include "list.h"

int list_push_data(list_t *list, void *data)
{
    node_t *node = list_create_node(data);

    if (node == NULL)
        return LIST_FAILURE;
    list_push_node(list, node);
    return LIST_SUCCESS;
}

void list_push_node(list_t *list, node_t *node)
{
    if (!node || !list)
        return;
    list->lenght++;
    if (!list->tail) {
        list->head = node;
        list->tail = node;
        return;
    }
    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    return;
}
