/*
** EPITECH PROJECT, 2022
** objdump.c
** File description:
** objdump
*/

#include "includes.h"

bool ehdr(void *buf)
{
    Elf64_Ehdr *ehdr32 = buf;
    size_t type = IS_32 ? ehdr32->e_type : ((Elf64_Ehdr *)buf)->e_type;

    if (ehdr32 == (void *)-1 || ehdr32->e_ident == 0 ||
        !(ehdr32->e_ident[EI_MAG0] == ELFMAG0 && ehdr32->e_ident[EI_MAG1] == 'E'
        && ehdr32->e_ident[EI_MAG2] == 'L' && ehdr32->e_ident[EI_MAG3] == 'F'))
        return false;
    printf("%sarchitecture: ", IS_32 ? "elf32-i386\n" : "elf64-x86-64\n");
    printf("%s, flags 0x", IS_32 ? "i386" : "i386:x86-64");
    if (type == ET_NONE || type == ET_CORE)
        printf("00000000:\n\n");
    if (type == ET_REL)
        printf("00000011:\nHAS_RELOC, HAS_SYMS\n");
    if (type == ET_EXEC)
        printf("00000112:\nEXEC_P, HAS_SYMS, D_PAGED\n");
    if (type == ET_DYN)
        printf("00000150:\nHAS_SYMS, DYNAMIC, D_PAGED\n");
    printf(IS_32 ? "start address 0x%08x\n\n" : "start address 0x%016x\n\n",
    (unsigned int)(IS_32 ? ehdr32->e_entry : ((Elf64_Ehdr *)buf)->e_entry));
    return true;
}

int main(int ac, char **av)
{
    struct stat st;
    char *path = "a.out";

    for (int i = 0, fd; i != ac - (ac == 1 ? 0 : 1); i++) {
        if (av[i + 1])
            path = av[i + 1];
        printf("\n%s:     file format ", path);
        if (stat(path, &st) == -1)
            ERROR("nm: '%s': No such file\n");
        if ((fd = open(path, O_RDONLY)) == -1)
            ERROR("nm: %s: Permission denied\n");
        if (!ehdr(mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0))) {
            close(fd);
            ERROR("nm: %s: file format not recognized\n");
        }
    }
    return 0;
}