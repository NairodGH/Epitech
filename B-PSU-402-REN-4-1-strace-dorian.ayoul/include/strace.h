/*
** EPITECH PROJECT, 2022
** strace.h
** File description:
** strace
*/

#pragma once

#include <asm/unistd_64.h>
#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <unistd.h>

#define ERROR_CODE 84
#define SYSCALL_HEX 0x50F
#define SYSCALL_TABLE_SIZE 330
#define STR_MAX_SIZE 32
#define ORIG regs.orig_rax
#define CHECK(func) if ((func) == -1) return ERROR_CODE

typedef unsigned long long reg_size;

typedef struct syscall_s {
    int id;
    const char *name;
    char args_nb;
    char ret;
    char args[6];
} syscall_t;
