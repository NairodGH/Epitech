/*
** EPITECH PROJECT, 2020
** str_functions.c
** File description:
** useful str-related functions for my_ls
*/

#include <sys/sysmacros.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "include/my.h"

void swapstr(char **str1, char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *putstr(char *str, int nb, char mode)
{
    int k = 0;

    if (mode == 't') {
        for (int i = 0; i != 3; i++)
            for (int j = 0; str[j + 1] != '\0'; j++) str[j] = str[j + 1];
        str[13] = ' ', str[14] = '\0';
        return (str);
    }
    if (mode == 'n') {
        for (int i = 0; i != 8; k++) (str[k] == ' ') && (i++);
        for (; str[k] != '\0'; k++) write(1, &str[k], 1);
    }
    if (mode == 's') write(1, str, my_len(str, 0)), write(1, "\n", 1);
    if (mode == 'i') {
        if (nb > 9) {
            putstr("0", nb / 10, 'i');
            my_putchar((nb % 10) + 48);
        }
        else my_putchar((nb % 10) + 48);
    }
}

int my_len(char *str, int nb)
{
    int i = 0;
    int j = 1;

    if (nb == 0) {
        while (str[i] != '\0')
            i++;
        return (i);
    }
    if (str[0] == '\0') {
        for (i = 1; nb / i >= 10;)
            i *= 10, j++;
        return (j);
    }
}

int put_in_str(char *dest, int k, char *srcstr, int srcnbr)
{
    int i = 1;

    for (int j = 0; srcstr[j] != '\0'; j++, k++)
        dest[k] = srcstr[j];
    while (srcnbr / i >= 10)
        i *= 10;
    for (int j = 0; i > 0 && srcnbr != 0; j++, k++) {
        dest[k] = (srcnbr / i) % 10 + 48;
        i /= 10;
    }
    return (k);
}