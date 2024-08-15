/*
** EPITECH PROJECT, 2022
** zappy
** File description:
** include
*/

#ifndef UTILS_H
    #define UTILS_H

    #ifndef _GNU_SOURCE
        #define _GNU_SOURCE
    #endif

    #ifndef _XOPEN_SOURCE
        #define _XOPEN_SOURCE 700
    #endif

    #include <math.h>
    #include <stdio.h>

    #ifndef SUCCESS
        #define SUCCESS (0)
    #endif
    #ifndef ERROR
        #define ERROR (1)
    #endif
    #ifndef EXIT
        #define EXIT (2)
    #endif

    #define UNUSED __attribute__((unused))

typedef struct {
    ssize_t x;
    ssize_t y;
} pos_t;

typedef struct {
    ssize_t x;
    ssize_t y;
} vector_t;

#endif // UTILS_H
