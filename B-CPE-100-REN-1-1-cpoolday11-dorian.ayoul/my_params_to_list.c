/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** Creates a new list from the command line arguments
*/

#include "my.h"
#include "mylist.h"
#include <stddef.h>

linked_list_t new_block(linked_list_t **block, void *data)
{
    linked_list_t *new_block = malloc(sizeof(linked_list_t));

    new_block->data = data;
    new_block->next = *block;
    *block = new_block;
    return (0);
}

linked_list_t *my_params_to_list(int ac, char * const av)
{
    linked_list_t *block = NULL;

    for (int i = 0; i < ac; i) {
        new_block(&block, av[i]);
    }
    return (block);
}