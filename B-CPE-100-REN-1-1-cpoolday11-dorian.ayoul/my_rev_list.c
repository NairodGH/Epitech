/*
** EPITECH PROJECT, 2020
** my_rev_list.c
** File description:
** Reverses the order of the list's elements
*/

#include "my.h"
#include "mylist.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *block = *begin;
    linked_list_t *block_swap = NULL;
    linked_list_t *next_block = NULL;

    while (*block != NULL) {
        next_block = block->next;
        block->next = block_swap;
        block_swap = block;
        block = next_block;
    }
    block->next = block_swap;
    *begin = block_swap;
}