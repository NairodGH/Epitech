/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "linked_list.h"

node_t *create_node(void *data)
{
    node_t *node = calloc(1, sizeof(node_t));

    if (!node)
        return NULL;
    node->data = data;
    return node;
}

void destroy_node(node_t *node, void (*free_data)(void *))
{
    if (!node)
        return;
    if (free_data)
        free_data(node->data);
    free(node);
}

void destroy_string(void *data)
{
    free(data);
}
