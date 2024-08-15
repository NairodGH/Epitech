/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef BFILE_H
#define BFILE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "blib.h"
#include "blib.h"

#define READ_SIZE 1024

typedef struct {
    char *file;
    size_t len;
} file_t;

char *bread_fd(int fd, size_t size_read);
char *bread_file(char *path, size_t size_read);
file_t *bread_file_len(char *path, size_t size_read);
file_t *create_file(size_t buff_size, size_t len);
void destroy_file(file_t *file);

#endif // BFILE_H
