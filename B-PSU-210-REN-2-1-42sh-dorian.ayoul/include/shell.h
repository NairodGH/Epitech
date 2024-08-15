/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef SHELL_H
#define SHELL_H

#include "linked_list.h"

typedef struct {
    list_t *parsing;
    list_t *env;
    list_t *variable;
} shell_t;

#endif // SHELL_H
