/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

static maped_lib_t *create_maped_lib(char *lib_path)
{
    maped_lib_t *lib = calloc(1, sizeof(maped_lib_t));

    if (lib == NULL) {
        return NULL;
    }
    lib->lib_path = strdup(lib_path);
    return lib;
}

void destroy_maped_lib(void *lib)
{
    maped_lib_t *maped_lib = (maped_lib_t *)lib;

    if (maped_lib == NULL) {
        return;
    }
    free(maped_lib->lib_path);
    free(maped_lib);
}

static void parse_maps_line(linked_list_t *list, maped_lib_t **lib,
                                        char *lib_path, char *line)
{
    if ((*lib) == NULL) {
        (*lib) = create_maped_lib(lib_path);
        if ((*lib) == NULL) {
            return;
        }
    }
    if (strcmp(lib_path, (*lib)->lib_path) != 0) {
        add_maped_lib(list, (*lib));
        (*lib) = create_maped_lib(lib_path);
        if ((*lib) == NULL) {
            return;
        }
    }
    get_addr(line, (*lib));
}

linked_list_t *parse_maps_file(linked_list_t *list, file_t *file)
{
    char *line = strtok(file->file, "\n");
    char *lib_path = NULL;
    maped_lib_t *temp = NULL;

    for (size_t i = 0; line != NULL; line = strtok(NULL, "\n"), i++) {
        lib_path = get_lib_path(line);
        if (lib_path == NULL)
            continue;
        parse_maps_line(list, &temp, lib_path, line);
    }
    if (temp != NULL) {
        add_maped_lib(list, temp);
    }
    destroy_file(file);
    return list;
}

linked_list_t *get_parsed_maps(pid_t pid)
{
    linked_list_t *list = NULL;
    file_t *file = NULL;

    list = create_linked_list();
    if (list == NULL)
        return (NULL);
    list->free_data = destroy_maped_lib;
    file = get_maps_file(pid);
    if (file == NULL || file->file == NULL)
        return NULL;
    return parse_maps_file(list, file);
}
