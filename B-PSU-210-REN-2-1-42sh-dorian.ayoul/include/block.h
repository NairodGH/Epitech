/*
** EPITECH PROJECT, 2020
** 42sh.h
** File description:
** 24/03/2021
*/

#ifndef BLOCK_H
#define BLOCK_H

#include "shell.h"
#include "return.h"

typedef struct {
    char *separator;
    int id_type;
    int id_elem;
    char **cmd_block;
    int fd;
    bool need_fd;
    int save_err;
} block_t;

typedef struct {
    int id_elem;
    bool (*func)(return_t *, block_t *, block_t *);
} block_verif_t;

bool verif_block(shell_t *shell, return_t *ret);

bool verif_or(return_t *ret, block_t *last, block_t *next);
bool verif_and(return_t *ret, block_t *last, block_t *next);
bool verif_left_right(return_t *ret, block_t *last, block_t *next);
bool verif_pipe(return_t *ret, block_t *last, block_t *next);

#endif // BLOCK_H
