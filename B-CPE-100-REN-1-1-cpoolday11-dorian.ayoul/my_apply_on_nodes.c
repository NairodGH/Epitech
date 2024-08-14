/*
** EPITECH PROJECT, 2020
** my_apply_on_nodes
** File description:
** Applies a function to the data of each node on the list
*/

#include "my.h"
#include "mylist.h"
#include <stddef.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *block = *begin;

    while (block->next != NULL) {
        (*f)(block->data);
        block = block->next;
    }
    return (0);
}