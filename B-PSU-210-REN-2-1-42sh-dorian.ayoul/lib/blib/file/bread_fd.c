/*
** EPITECH PROJECT, 2021
** bread based on existing fd
** File description:
** bread_fd
*/

#include "blib.h"

static char *create_str(char *str, size_t size)
{
    char *result = bstrndup(str, size);

    if (result) {
        bmemset(result + bstrlen(str), '\0', size + 1 - bstrlen(str));
    }
    free(str);
    return result;
}

static char *bloop_read(int fd, char *temp, char *buffer, size_t size_read)
{
    int ret = 1;
    int iter = 0;
    int len = size_read;

    do {
        iter++;
        len = (iter * size_read);
        bmemset(temp, '\0', size_read + 1);
        ret = read(fd, temp, size_read);
        buffer = bstrcat(create_str(buffer, len + ret), temp);
        if (!buffer)
            return NULL;
        if (ret == (int)size_read && !temp[ret - 1])
            break;
    } while (ret == (int)size_read);
    return buffer;
}

char *bread_fd(int fd, size_t size_read)
{
    char *temp = malloc(sizeof(char) * (size_read + 1));
    char *buffer = bcalloc(sizeof(char), size_read + 1);

    if (!temp || !buffer)
        return NULL;
    buffer = bloop_read(fd, temp, buffer, size_read);
    free(temp);
    close(fd);
    return buffer;
}
