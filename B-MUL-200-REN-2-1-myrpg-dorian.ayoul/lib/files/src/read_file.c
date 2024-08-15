/*
** EPITECH PROJECT, 2021
** read_file.c
** File description:
** Read file
*/

#include <file_utils.h>
#include <nep/nmem.h>

PRIVATE nsize_t get_file_size(char const *path)
{
    struct stat file;

    if (stat(path, &file) == -1)
        return 0;
    return (file.st_size);
}

char *read_file(char const *path)
{
    nsize_t size = get_file_size(path);
    char *buf = ncalloc(1, size + 1);
    int fd = open(path, O_RDONLY);

    if (read(fd, buf, size) == -1) {
        close(fd);
        return NULL;
    }
    close(fd);
    return buf;
}