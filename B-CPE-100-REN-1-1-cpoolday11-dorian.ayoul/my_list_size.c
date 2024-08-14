/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** Returns number of elements in the list
*/

#include "my.h"
#include "mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *block;

    block = begin;
    for (int size = 0; block != NULL; size++) {
        block = block->next;
    }
    return (size);
}