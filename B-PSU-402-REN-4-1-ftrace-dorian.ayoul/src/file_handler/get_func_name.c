/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

static Elf *init_elf(int fd)
{
    Elf *elf = NULL;

    if (elf_version(EV_CURRENT) == EV_NONE)
        return NULL;
    elf = elf_begin(fd, ELF_C_READ, NULL);
    if (elf == NULL)
        return NULL;
    if (elf_kind(elf) != ELF_K_ELF) {
        elf_end(elf);
        return NULL;
    }
    return elf;
}

static char *handle_lib_file(maped_lib_t *lib, size_t addr)
{
    Elf *elf = NULL;
    char *name = NULL;
    int fd = open(lib->lib_path, O_RDONLY);

    if (fd == -1)
        return NULL;
    elf = init_elf(fd);
    if (elf == NULL)
        return NULL;
    name = handle_elf(elf, addr);
    close(fd);
    elf_end(elf);
    return name;
}

char *get_func_name(linked_list_t *lib_list, size_t addr)
{
    maped_lib_t *lib = NULL;

    for (node_t *node = lib_list->head; node != NULL; node = node->next) {
        lib = node->data;
        if (lib->lib_start <= addr && addr <= lib->lib_end) {
            return handle_lib_file(lib, addr);
        }
    }
    return NULL;
}
