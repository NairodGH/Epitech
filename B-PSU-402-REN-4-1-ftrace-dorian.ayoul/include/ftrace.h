/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** include
*/

#ifndef FTRACE_H
    #define FTRACE_H

    #define _GNU_SOURCE 1

    #define SUCCESS (0)
    #define ERROR (1)

    #define BUFFER_SIZE (1024)
    #define ARG_START (2)

    #define UNUSED __attribute__((unused))

    #include <bits/types/siginfo_t.h>

    #include <sys/ptrace.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    #include <sys/user.h>
    #include <sys/stat.h>

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    #include <getopt.h>
    #include <elf.h>
    #include <libelf.h>
    #include <errno.h>
    #include <signal.h>
    #include <inttypes.h>
    #include <ctype.h>
    #include <fcntl.h>

    #include "syscall.h"
    #include "linked_list.h"

typedef struct user_regs_struct user_regs_struct_t;

typedef struct {
    char *name;
    pid_t pid;
    user_regs_struct_t *regs;
    linked_list_t *stack;
    int status;
    long ret;
} ftrace_t;

typedef struct {
    char *fileName;
    char **argv;
} args_t;

typedef struct {
    size_t code;
    int (*function)(ftrace_t *ftrace, size_t rip_val);
} call_array_t;

typedef struct {
    char *lib_path;
    size_t lib_start;
    size_t lib_end;
} maped_lib_t;

typedef struct {
    int si_signo;
    char *string;
} signal_t;

typedef struct {
    size_t file_size;
    void *file;
} file_t;

void destroy_file(file_t *file);
file_t *read_file(int fd);

bool get_section_hdr(Elf *elf, Elf64_Shdr **hdr, Elf_Scn **scn,
                                                    size_t type);
bool get_section_hdr_by_name(Elf *elf, Elf64_Shdr **hdr, Elf_Scn **scn,
                                                    const char *name);
char *handle_elf(Elf *elf, size_t addr);

char *get_func_name(linked_list_t *lib_list, size_t addr);
char *get_lib_path(char *line);
void get_addr(char *line, maped_lib_t *lib);

void add_maped_lib(linked_list_t *list, maped_lib_t *lib);
void destroy_maped_lib(void *lib);
void destroy_string(void *data);

file_t *get_maps_file(pid_t pid);
linked_list_t *parse_maps_file(linked_list_t *list, file_t *file);
linked_list_t *get_parsed_maps(pid_t pid);

ftrace_t *create_ftrace(void);
void destroy_ftrace(ftrace_t *ftrace);

int enter_func(ftrace_t *ftrace, size_t addr);
int all_returns(ftrace_t *ftrace, size_t rip_val);
int call_e8(ftrace_t *ftrace, size_t rip_val);
int call_ff(ftrace_t *ftrace, size_t rip_val);

size_t filter_param(size_t param, size_t nbr_params);

void handle_call(ftrace_t *ftrace);
void handle_syscall(ftrace_t *ftrace);
void handle_signal(ftrace_t *ftrace);
void handle_step(ftrace_t *ftrace);
void handle_exit(ftrace_t *ftrace);

pid_t ftrace_attach_process(pid_t pid);
int ftrace_loop(ftrace_t *ftrace);
int ftrace(args_t *args);

#endif // FTRACE_H
