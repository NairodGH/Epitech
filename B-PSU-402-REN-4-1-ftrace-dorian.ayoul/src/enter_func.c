/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace_loop
*/

#include "ftrace.h"

static char *get_unknow_name(size_t addr, char *name)
{
    char *func_name = NULL;

    if (asprintf(&func_name, "func_0x%lX@%s", addr, name) == -1) {
        return NULL;
    }
    return func_name;
}

static maped_lib_t *get_lib(linked_list_t *lib_list, size_t addr)
{
    maped_lib_t *lib = NULL;

    for (node_t *node = lib_list->head; node != NULL; node = node->next) {
        lib = node->data;
        if (lib->lib_start <= addr && addr <= lib->lib_end) {
            return lib;
        }
    }
    return NULL;
}

static bool get_libs_list(ftrace_t *ftrace, size_t addr,
            linked_list_t **libs_list, maped_lib_t **lib)
{
    *libs_list = get_parsed_maps(ftrace->pid);
    if (*libs_list == NULL)
        return false;
    *lib = get_lib(*libs_list, addr);
    if (*lib == NULL)
        return false;
    return true;
}

int enter_func(ftrace_t *ftrace, size_t addr)
{
    linked_list_t *libs_list = NULL;
    maped_lib_t *lib = NULL;
    char *function_name = NULL;
    node_t *node = NULL;

    if (get_libs_list(ftrace, addr, &libs_list, &lib) == false)
        function_name = get_unknow_name(addr, ftrace->name);
    if (function_name == NULL)
        function_name = get_func_name(libs_list, addr - lib->lib_start);
    if (function_name == NULL)
        function_name = get_func_name(libs_list, addr);
    if (function_name == NULL)
        function_name = get_unknow_name(addr, lib->lib_path);
    node = create_node(function_name);
    if (!node)
        return ERROR;
    destroy_linked_list(libs_list);
    fprintf(stderr, "Entering function %s at 0x%lx\n", function_name, addr);
    push_list(ftrace->stack, node);
    return SUCCESS;
}
