/*
** EPITECH PROJECT, 2021
** parsing core
** File description:
** parser
*/

#include "42sh.h"

parser_t *create_parser(size_t adv, size_t len)
{
    parser_t *result = bcalloc(sizeof(parser_t), 1);

    if (result) {
        result->adv = adv;
        result->len = len;
    }
    return result;
}

elem_t *create_elem(char *elem, int id_type, int id_elem)
{
    elem_t *result = bcalloc(sizeof(elem_t), 1);

    if (result) {
        result->elem = elem;
        if (id_type == D_DELIM) {
            result->id_type = ID_WITHOUT;
            result->id_elem = ID_WITHOUT;
        }
        else {
            result->id_type = id_type;
            result->id_elem = id_elem;
        }
    }
    return result;
}

block_t *create_elem_block(elem_t *elem, size_t alloc_size)
{
    block_t *block = calloc(1, sizeof(block_t));

    if (!block)
        return NULL;
    if (elem->id_type != ID_WITHOUT) {
        block->cmd_block = NULL;
        block->separator = strdup(elem->elem);
        block->id_type = elem->id_type;
        block->id_elem = elem->id_elem;
    }
    else if (elem->id_type == ID_WITHOUT) {
        block->separator = NULL;
        block->cmd_block = binit_array_light(alloc_size + 1);
        block->fd = 0;
        block->id_type = ID_WITHOUT;
        block->id_elem = ID_WITHOUT;
    }
    if (block->separator == NULL && block->cmd_block == NULL)
        return NULL;
    return block;
}
