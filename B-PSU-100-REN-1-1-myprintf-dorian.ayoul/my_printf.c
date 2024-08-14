/*
** EPITECH PROJECT, 2020
** print f.c
** File description:
** print f-like function
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "include/my.h"

void conversion_spec(char *format, int i, va_list list, char **flags)
{
    if (format[i] == 'd' || format[i] == 'i')
        my_putint(va_arg(list, long), flags);
    if (format[i] == 'o') my_putoct(va_arg(list, unsigned long), flags);
    if (format[i] == 'u') my_putuns(va_arg(list, unsigned long), flags);
    if (format[i] == 'x') my_puthex(va_arg(list, unsigned long), 'x', flags);
    if (format[i] == 'X') my_puthex(va_arg(list, unsigned long), 'X', flags);
    if (format[i] == 'p') my_puthex(va_arg(list, unsigned long), 'p', flags);
    if (format[i] == 'b') my_putbin(va_arg(list, unsigned long), flags);
    if (format[i] == 'c') my_putchar(va_arg(list, int), flags);
    if (format[i] == 's') my_putstr(va_arg(list, char *), 's', flags);
    if (format[i] == 'S') my_putstr(va_arg(list, char *), 'S', flags);
}

int format_flags(char *format, int i, char **flags, int j)
{
    if (format[i] == '#')
        flags[0][0] = '#';
    if (format[i] == ' ' && flags[0][1] != 'N')
        flags[0][1] = ' ';
    if (format[i] == '+')
        (flags[0][2] = '+', flags[0][1] = 'N');
    if (format[i] == '0' && flags[1][0] != 'N' && !('0' <= format[i - 1] &&
        format[i - 1] <= '9'))
        flags[1][0] = '0';
    else if ('0' <= format[i] && format[i] <= '9' && format[i - 1] != '.' &&
        format[i - 2] != '.')
        flags[2][j++] = format[i];
    if (format[i] == '-' && flags[1][1] != 'N')
        (flags[1][1] = '-', flags[1][0] = 'N');
    if (format[i] == '.' && j == 0)
        (flags[1][2] = '.', flags[1][1] = 'N', flags[1][0] = 'N');
    if (format[i] == 'h')
        flags[3][0] = 'h';
    (format[i] == 'l') && (flags[3][0] = 'l');
    return (j);
}

int is_flag(char *format, int i, va_list list, char **flags)
{
    for (int j = 0; '0' <= format[i] && format[i] <= '9' || format[i] == '#' ||
    format[i] == '0' || format[i] == '-' || format[i] == ' ' ||
    format[i] == '+' || format[i] == '.' || format[i] == 'h' ||
    format[i] == 'l' || format[i] == 'd' || format[i] == 'i' ||
    format[i] == 'o' || format[i] == 'u' || format[i] == 'x' ||
    format[i] == 'X' || format[i] == 'c' || format[i] == 's' ||
    format[i] == 'S' || format[i] == 'p' || format[i] == 'b'; ++i) {
        j = format_flags(format, i, flags, j);
        if (format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
        format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
        format[i] == 'c' || format[i] == 's' || format[i] == 'S' ||
        format[i] == 'p' || format[i] == 'b') {
            conversion_spec(format, i, list, flags);
            return (++i);
        }
    }
    return (i);
}

void my_printf(char *format, ...)
{
    va_list list;
    int check_char = 0;
    char *flags[4];

    va_start(list, format);
    for (int i = 0; i < my_strlen(format);) {
        if (format[i] == '%') {
            for (int rows = 0; rows < 4; rows++) flags[rows] = malloc(10);
            for (int rows = 0; rows < 4; rows++)
                for (int col = 0; col < 10; col++) flags[rows][col] = '\0';
            check_char = ++i;
            i = is_flag(format, i, list, flags);
            if (check_char == i && format[i] == '%') write(1, &format[i++], 1);
            if (check_char == i && format[i] != '%')
                write(1, "%", 1), write(1, &format[i++], 1);
            for (int rows = 0; rows < 4; rows++) free(flags[rows]);
        }
        else write(1, &format[i++], 1);
    }
    va_end(list);
}