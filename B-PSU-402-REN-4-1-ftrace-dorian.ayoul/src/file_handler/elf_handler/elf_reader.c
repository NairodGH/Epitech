/*
** EPITECH PROJECT, 2022
** Ftrace
** File description:
** ftrace
*/

#include "ftrace.h"

static size_t get_plt_addr(Elf *elf, size_t idx)
{
    Elf64_Shdr *hdr = NULL;
    Elf_Scn *scn = NULL;

    get_section_hdr_by_name(elf, &hdr, &scn, ".plt");
    return hdr->sh_addr + hdr->sh_entsize * idx;
}

static size_t get_plt_entry(Elf *elf)
{
    Elf64_Shdr *hdr = NULL;
    Elf_Scn *scn = NULL;

    get_section_hdr_by_name(elf, &hdr, &scn, ".plt");
    return hdr->sh_entsize ? hdr->sh_size / hdr->sh_entsize : 0;
}

static char *get_name(Elf *elf, Elf64_Shdr *hdr, Elf_Scn *scn, size_t addr)
{
    Elf_Data *sym_data = elf_getdata(scn, NULL);
    Elf64_Sym *symtab = (Elf64_Sym *)sym_data->d_buf;
    size_t nbr_elem = hdr->sh_size / hdr->sh_entsize;

    for (size_t i = 0; i < nbr_elem; i++) {
        if (symtab[i].st_value == addr) {
            return strdup(elf_strptr(elf, hdr->sh_link,
                                            symtab[i].st_name));
        }
    }
    return NULL;
}

static char *get_dyn_name(Elf *elf, Elf64_Shdr *hdr, Elf_Scn *scn,
                                                    size_t addr)
{
    Elf64_Shdr *relhdr = NULL;
    Elf_Scn *rela_scn = NULL;
    Elf_Data *rela_data = NULL;
    Elf64_Rela *rela = NULL;
    Elf_Data *dyn_data = elf_getdata(scn, NULL);
    Elf64_Sym *dyntab = dyn_data ? (Elf64_Sym *)dyn_data->d_buf : NULL;
    size_t nbr_elem = 0;

    if (get_section_hdr(elf, &relhdr, &rela_scn, SHT_RELA) == false)
        return NULL;
    nbr_elem = relhdr->sh_entsize ? relhdr->sh_size / relhdr->sh_entsize : 0;
    rela_data = elf_getdata(rela_scn, NULL);
    rela = (Elf64_Rela *)rela_data->d_buf;
    for (size_t i = 0; i < nbr_elem; i++) {
        if (get_plt_addr(elf, i) == addr) {
            return strdup(elf_strptr(elf, hdr->sh_link,
                dyntab[ELF64_R_SYM(rela[i].r_info)].st_name));
        }
    }
    return NULL;
}

char *handle_elf(Elf *elf, size_t addr)
{
    Elf64_Shdr *hdr = NULL;
    Elf_Scn *scn = NULL;
    char *name = NULL;

    if (get_section_hdr(elf, &hdr, &scn, SHT_SYMTAB))
        name = get_name(elf, hdr, scn, addr);
    if (name == NULL && get_section_hdr(elf, &hdr, &scn, SHT_DYNSYM))
        name = get_dyn_name(elf, hdr, scn, addr - (16 * get_plt_entry(elf)));
    if (name == NULL)
        return get_dyn_name(elf, hdr, scn, addr);
    return NULL;
}
