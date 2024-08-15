/*
** EPITECH PROJECT, 2022
** includes.c
** File description:
** includes
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

#pragma once

#define IS_32       (((Elf32_Ehdr *)buf)->e_ident[EI_CLASS] == ELFCLASS32)
#define IS_OBJECT   ELF32_ST_TYPE(info) == STT_OBJECT
#define OFFSET32    shdr32[shdr32[i].sh_link].sh_offset
#define OFFSET64    shdr64[shdr64[i].sh_link].sh_offset
#define SIZE32      shdr32[i].sh_size / shdr32[i].sh_entsize
#define SIZE64      shdr64[i].sh_size / shdr64[i].sh_entsize
#define INFO32      sym32[j].st_info
#define INFO64      sym64[j].st_info
#define SHNDX32     sym32[j].st_shndx
#define SHNDX64     sym64[j].st_shndx
#define FLAG32      shdr32[sym32[j].st_shndx].sh_flags
#define FLAG64      shdr64[sym64[j].st_shndx].sh_flags
#define TYPE32      shdr32[sym32[j].st_shndx].sh_type
#define TYPE64      shdr64[sym64[j].st_shndx].sh_type
#define NAME32      &name[sym32[j].st_name]
#define NAME64      &name[sym64[j].st_name]
#define ERROR(str)  return (fprintf(stderr, str, path) * 0 + 84)