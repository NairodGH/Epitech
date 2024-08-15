/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main
*/

#include "list.h"

node_t *list_create_node(void *data)
{
    node_t *result = calloc(sizeof(node_t), 1);

    if (result) {
        result->data = data;
    }
    return result;
}

void list_destroy_node(node_t *node, void (*destroy_data)(void *data))
{
    if (node == NULL)
        return;
    if (destroy_data)
        destroy_data(node->data);
    free(node);
}
