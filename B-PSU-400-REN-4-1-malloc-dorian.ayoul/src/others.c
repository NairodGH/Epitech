/*
** EPITECH PROJECT, 2022
** others.c
** File description:
** others
*/

#include "../include/malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    void *block;
    size_t overflow_check = nmemb * size;

    if (overflow_check / nmemb != size) {
        errno = ENOMEM;
        return NULL;
    }
    block = malloc(nmemb * size);
    memset(block, 0, nmemb * size);
    return block;
}

void *realloc(void *ptr, size_t size)
{
    block_t *ptr_meta = ptr - sizeof(block_t);
    void *block;

    if (!ptr)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (size <= ptr_meta->size)
        return ptr;
    if (!(block = malloc(size)))
        return NULL;
    memcpy(block, ptr, ptr_meta->size);
    free(ptr);
    return block;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t overflow_check = nmemb * size;

    if (overflow_check / nmemb != size) {
        errno = ENOMEM;
        return NULL;
    }
    return realloc(ptr, nmemb * size);
}