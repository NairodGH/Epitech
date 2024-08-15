/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** main
*/

#include "list.h"

void list_print_list(list_t *list, void (*print_data)(void *))
{
    node_t *node_temp = NULL;

    foreach(list->head, node_temp) {
        print_data(node_temp->data);
    }
}
