/*
** EPITECH PROJECT, 2022
** malloc.h
** File description:
** malloc
*/

#pragma once

#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct block_s {
    struct block_s *next;
    size_t size;
    bool is_free;
} block_t;

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);