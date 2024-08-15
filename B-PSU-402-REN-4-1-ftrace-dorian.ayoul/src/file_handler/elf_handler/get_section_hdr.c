/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

bool get_section_hdr(Elf *elf, Elf64_Shdr **hdr, Elf_Scn **scn,
                                                    size_t type)
{
    while ((*scn = elf_nextscn(elf, *scn)) != NULL) {
        *hdr = elf64_getshdr(*scn);
        if (*hdr == NULL) {
            return NULL;
        } else if ((*hdr)->sh_type == type) {
            return true;
        }
    }
    return false;
}

bool get_section_hdr_by_name(Elf *elf, Elf64_Shdr **hdr, Elf_Scn **scn,
                                                    const char *name)
{
    Elf64_Ehdr *ehdr = elf64_getehdr(elf);
    size_t shstrtab_idx = 0;

    if (ehdr == NULL)
        return false;
    shstrtab_idx = ehdr->e_shstrndx;
    while ((*scn = elf_nextscn(elf, *scn)) != NULL) {
        *hdr = elf64_getshdr(*scn);
        if (*hdr == NULL) {
            return NULL;
        } else if (strcmp(elf_strptr(elf, shstrtab_idx,
                        (*hdr)->sh_name), name) == 0) {
            return true;
        }
    }
    return false;
}
