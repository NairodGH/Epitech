/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

static char *get_maps_file_path(pid_t pid)
{
    char *path = NULL;

    if (asprintf(&path, "/proc/%d/maps", pid) == -1)
        return NULL;
    return path;
}

file_t *get_maps_file(pid_t pid)
{
    char *file_path = get_maps_file_path(pid);
    file_t *file = NULL;
    int fd = 0;

    if (file_path == NULL)
        return NULL;
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        free(file_path);
        return NULL;
    }
    free(file_path);
    file = read_file(fd);
    close(fd);
    return file;
}
