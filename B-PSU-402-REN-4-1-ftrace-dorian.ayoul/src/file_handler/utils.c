/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

char *get_lib_path(char *line)
{
    char *lib_path = NULL;

    for (size_t i = 0; line[i] != '\0'; i++) {
        if (line[i] == '/') {
            lib_path = &line[i];
            break;
        }
    }
    if (lib_path == NULL) {
        return NULL;
    }
    for (size_t i = 0; lib_path[i] != '\0'; i++) {
        if (strncmp(&lib_path[i], ".so", 3) == 0) {
            return lib_path;
        }
    }
    return NULL;
}

void add_maped_lib(linked_list_t *list, maped_lib_t *lib)
{
    node_t *node = create_node(lib);

    if (node == NULL) {
        return;
    }
    emplace_back_list(list, node);
}

void get_addr(char *line, maped_lib_t *lib)
{
    if (lib->lib_start == 0) {
        lib->lib_start = strtoul(line, NULL, 16);
    }
    for (; *line != '\0'; line = (char *)(((size_t)line) + 1)) {
        if (*line == '-') {
            line = (char *)(((size_t)line) + 1);
            break;
        }
    }
    lib->lib_end = strtoul(line, NULL, 16);
}
