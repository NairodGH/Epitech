/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main
*/

#include "list.h"

void list_remove_node(list_t *list, node_t *node)
{
    if (!node || !list)
        return;
    list->lenght--;
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    node->prev = NULL;
    node->next = NULL;
}

void *list_pop_last(list_t *list)
{
    node_t *node = list->tail;
    void *data = NULL;

    if (list->tail == NULL)
        return (NULL);
    data = node->data;
    list_remove_node(list, node);
    list_destroy_node(node, NULL);
    return data;
}

void *list_pop_head(list_t *list)
{
    node_t *node = list->head;
    void *data = NULL;

    if (list->head == NULL)
        return (NULL);
    data = node->data;
    list_remove_node(list, node);
    list_destroy_node(node, NULL);
    return data;
}

void list_destroy_data_node(list_t *list, void *data,
    void (*destroy_data)(void *))
{
    node_t *node = NULL;
    node_t *safe = NULL;

    if (!list)
        return;
    foreach_safe(list->head, node, safe) {
        if (node->data == data) {
            list_remove_node(list, node);
            list_destroy_node(node, destroy_data);
            return;
        }
    }
}
