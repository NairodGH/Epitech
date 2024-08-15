/*
** EPITECH PROJECT, 2022
** malloc.c
** File description:
** malloc
*/

#include "../include/malloc.h"

block_t *add_block(block_t *block, size_t size, intptr_t pages, bool is_first)
{
    block_t *last;

    if (is_first && (block = sbrk(pages)) == (void *) - 1)
        return NULL - sizeof(block_t);
    last = (void *)block + sizeof(block_t) + size;
    last->is_free = true;
    block->next = NULL;
    block->is_free = false;
    if (is_first && size + sizeof(block_t) * 2 <= pages) {
        last->next = NULL;
        last->size = pages - (size + sizeof(block_t) * 2);
        block->next = last;
    }
    if (!is_first) {
        last->next = block->next;
        last->size = block->size - (sizeof(block_t) + size);
        block->next = last;
    }
    block->size = size;
    return block;
}

block_t *get_block(block_t *first, size_t size, intptr_t pages)
{
    block_t *block = NULL;

    for (block_t *tmp = first; tmp; tmp = tmp->next)
        if ((!block || block && tmp->size < block->size) &&
            tmp->size >= size + sizeof(block_t) && tmp->is_free)
            block = tmp;
    return add_block(block, size, pages, !block);
}

void *malloc(size_t size)
{
    intptr_t pages = sysconf(_SC_PAGESIZE) * 2;
    static block_t *first = NULL;

    if (size == 0)
        return NULL;
    while (pages < size + sizeof(block_t))
        pages += sysconf(_SC_PAGESIZE) * 2;
    if (!first)
        return add_block(first, size, pages, 1) + 1;
    return get_block(first, size, pages) + 1;
}

void free(void *ptr)
{
    block_t *block = ptr - sizeof(block_t);

    if (ptr && block && !block->is_free)
        block->is_free = true;
}