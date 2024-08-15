/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "linked_list.h"

linked_list_t *create_linked_list(void)
{
    linked_list_t *list = calloc(1, sizeof(linked_list_t));

    return list;
}

void destroy_linked_list(linked_list_t *list)
{
    node_t *tmp = NULL;

    if (!list)
        return;
    for (node_t *node = list->head; node != NULL; node = tmp) {
        tmp = node->next;
        destroy_node(node, list->free_data);
    }
    free(list);
}

void push_list(linked_list_t *list, node_t *node)
{
    if (!list || !node)
        return;
    node->next = list->head;
    list->head = node;
    list->nbr_elem++;
}

node_t *pop_list(linked_list_t *list)
{
    node_t *node = NULL;

    if (!list || !list->head)
        return NULL;
    node = list->head;
    list->head = list->head->next;
    list->nbr_elem--;
    return node;
}

void emplace_back_list(linked_list_t *list, node_t *node)
{
    node_t *tmp = NULL;

    if (!list || !node)
        return;
    list->nbr_elem++;
    for (tmp = list->head; tmp != NULL && tmp->next != NULL; tmp = tmp->next);
    if (tmp) {
        tmp->next = node;
    } else {
        list->head = node;
    }
}
