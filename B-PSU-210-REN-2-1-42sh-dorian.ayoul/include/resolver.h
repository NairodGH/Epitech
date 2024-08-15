/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef RESOLVER_H
#define RESOLVER_H

#include "shell.h"
#include "return.h"

#define WAS_EXEC -1

typedef struct {
    int id_elem;
    size_t to_skip;
    void (*resolv_func)(shell_t *, return_t *, block_t *, block_t *);
} resolver_t;

int get_block(int id_type);

// UTILS
void get_new_cmd(block_t *last, block_t *next);
void free_right(block_t *last, int fd, char *str);

void r_double_right(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_double_left(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_or(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_and(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_sep(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_left(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_right(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);
void r_pipe(shell_t *shell, return_t *ret,
    block_t *last, block_t *next);

void resolver(shell_t *shell, return_t *ret);

void print_fd(int fd);

#endif // RESOLVER_H
