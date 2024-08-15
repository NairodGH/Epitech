/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main
*/

#include "linked_list.h"

list_node_t *get_node(list_t *list, void *data)
{
    list_node_t *temp = NULL;

    foreach(list->head, temp) {
        if (temp->data == data)
            return temp;
    }
    return NULL;
}