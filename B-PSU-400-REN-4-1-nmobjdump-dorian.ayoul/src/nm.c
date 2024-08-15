/*
** EPITECH PROJECT, 2022
** nm.c
** File description:
** nm
*/

#include "includes.h"

char types(size_t info, size_t shndx, size_t flag, size_t type)
{
    if (ELF32_ST_BIND(info) == STB_WEAK)
        return (IS_OBJECT ? 'V' : 'W') + (shndx == SHN_UNDEF ? 32 : 0);
    if (shndx == SHN_UNDEF)
        return 'U' + (ELF32_ST_BIND(info) == STB_GNU_UNIQUE ? 32 : 0);
    if (shndx == SHN_ABS)
        return 'A';
    if (type == SHT_NOBITS)
        return 'B' + (ELF32_ST_BIND(info) == STB_LOCAL ? 32 : 0);
    if (shndx == SHN_COMMON)
        return 'C';
    if (type == SHT_PROGBITS && flag == SHF_ALLOC + SHF_EXECINSTR)
        return 'T' + (ELF32_ST_BIND(info) == STB_LOCAL ? 32 : 0);
    if (type == SHT_PROGBITS && flag == SHF_ALLOC)
        return 'R' + (ELF32_ST_BIND(info) == STB_LOCAL ? 32 : 0);
    if ((type == SHT_DYNAMIC || (type && flag == SHF_ALLOC + SHF_WRITE) ||
        ELF32_ST_TYPE(info) == STT_OBJECT || ELF32_ST_TYPE(info) == STT_NOTYPE))
        return 'D' + (ELF32_ST_BIND(info) == STB_LOCAL ? 32 : 0);
    return '?';
}

bool sym(void *buf, char *name, size_t nb, size_t i)
{
    Elf32_Ehdr *ehdr32 = buf;
    Elf32_Shdr *shdr32 = IS_32 ? buf + ehdr32->e_shoff : NULL;
    Elf32_Sym *sym32 = IS_32 ? buf + shdr32[i].sh_offset : NULL;
    Elf64_Ehdr *ehdr64 = buf;
    Elf64_Shdr *shdr64 = IS_32 ? NULL : buf + ehdr64->e_shoff;
    Elf64_Sym *sym64 = IS_32 ? NULL : buf + shdr64[i].sh_offset;

    for (size_t j = 0; IS_32 && j != nb; j++)
        if (sym32[j].st_info != STT_FILE && sym32[j].st_name != SHN_UNDEF) {
            printf(!sym32[j].st_size && !sym32[j].st_shndx ? "         "
            : "%08x ", (unsigned int)sym32[j].st_value);
            printf("%c %s\n", types(INFO32, SHNDX32, FLAG32, TYPE32), NAME32);
        }
    for (size_t j = 0; !IS_32 && j != nb; j++)
        if (sym64[j].st_info != STT_FILE && sym64[j].st_name != SHN_UNDEF) {
            printf(!sym64[j].st_size && !sym64[j].st_shndx ? "                 "
            : "%016x ", (unsigned int)sym64[j].st_value);
            printf("%c %s\n", types(INFO64, SHNDX64, FLAG64, TYPE64), NAME64);
        }
    return true;
}

bool ehdr(void *buf)
{
    Elf32_Ehdr *ehdr32 = buf;
    Elf32_Shdr *shdr32 = buf + (buf ? ehdr32->e_shoff : 0);
    Elf64_Ehdr *ehdr64 = buf;
    Elf64_Shdr *shdr64 = buf + (buf ? ehdr64->e_shoff : 0);

    if (buf == (void *)-1 || ehdr32->e_ident == 0 ||
        !(ehdr32->e_ident[0] == ELFMAG0 && ehdr32->e_ident[1] == 'E'
        && ehdr32->e_ident[2] == 'L' && ehdr32->e_ident[3] == 'F'))
        return false;
    for (size_t i = 0; IS_32 && i < ehdr32->e_shnum; i++)
        if (shdr32[i].sh_type == SHT_SYMTAB)
            return sym(buf, buf + OFFSET32, SIZE32, i);
    for (size_t i = 0; i < ehdr64->e_shnum; i++)
        if (shdr64[i].sh_type == SHT_SYMTAB)
            return sym(buf, buf + OFFSET64, SIZE64, i);
    return false;
}

int main(int ac, char **av)
{
    struct stat st;
    char *path = "a.out";

    for (int i = 0, fd; i != ac - (ac == 1 ? 0 : 1); i++) {
        if (av[i + 1])
            path = av[i + 1];
        if (ac > 2)
            printf("\n%s:\n", path);
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