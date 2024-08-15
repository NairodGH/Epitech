/*
** EPITECH PROJECT, 2021
** funcs to clear parse_elems
** File description:
** destroy_elem_parsing
*/

#include "42sh.h"

void destroy_elem(void *elem)
{
    elem_t *elem_cast = (elem_t *)elem;

    free(elem_cast->elem);
}

void destroy_elem_block(void *block)
{
    block_t *block_cast = (block_t *)block;

    if (block_cast->separator != NULL)
        free(block_cast->separator);
    else
        bfree_array(block_cast->cmd_block);
}
