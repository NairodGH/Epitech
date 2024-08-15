/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

void destroy_file(file_t *file)
{
    if (file == NULL || file->file == NULL)
        return;
    free(file->file);
    free(file);
}

file_t *read_file(int fd)
{
    file_t *file = calloc(1, sizeof(file_t));
    ssize_t size_read = 0;

    if (file == NULL)
        return NULL;
    do {
        file->file = realloc(file->file, file->file_size + BUFFER_SIZE);
        if (file->file == NULL)
            return NULL;
        bzero((void *)((size_t)file->file +
                        (size_t)file->file_size), BUFFER_SIZE);
        size_read = read(fd, file->file + file->file_size, BUFFER_SIZE);
        if (size_read <= 0) {
            destroy_file(file);
            return NULL;
        }
        file->file_size += size_read;
    } while (size_read == BUFFER_SIZE);
    return file;
}
