/*
** EPITECH PROJECT, 2021
** ftrace
** File description:
** syscalls table
*/

#ifndef     SYSCALL_H_
    #define     SYSCALL_H_

    #include    <stdlib.h>
    #include    "ftrace.h"

typedef struct {
    int code;
    char *name;
    size_t arg_num;
} __attribute__((packed))syscall_t;

syscall_t get_syscall(size_t idx);

#endif  /* !SYSCALL_H_ */
